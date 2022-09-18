/*************************************************************************/
/*  transform3d.hpp                                                      */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef GODOT_TRANSFORM3D_HPP
#define GODOT_TRANSFORM3D_HPP

#include <godot_cpp/core/math.hpp>
#include <godot_cpp/variant/aabb.hpp>
#include <godot_cpp/variant/basis.hpp>
#include <godot_cpp/variant/packed_vector3_array.hpp>
#include <godot_cpp/variant/plane.hpp>

namespace godot {

class Transform3D {
	_FORCE_INLINE_ GDNativeTypePtr _native_ptr() const { return (void *)this; }

	friend class Variant;

public:
	Basis basis;
	Vector3 origin;

	void invert();
	Transform3D inverse() const;

	void affine_invert();
	Transform3D affine_inverse() const;

	Transform3D rotated(const Vector3 &p_axis, real_t p_phi) const;

	void rotate(const Vector3 &p_axis, real_t p_phi);
	void rotate_basis(const Vector3 &p_axis, real_t p_phi);

	void set_look_at(const Vector3 &p_eye, const Vector3 &p_target, const Vector3 &p_up = Vector3(0, 1, 0));
	Transform3D looking_at(const Vector3 &p_target, const Vector3 &p_up = Vector3(0, 1, 0)) const;

	void scale(const Vector3 &p_scale);
	Transform3D scaled(const Vector3 &p_scale) const;
	void scale_basis(const Vector3 &p_scale);
	void translate(real_t p_tx, real_t p_ty, real_t p_tz);
	void translate(const Vector3 &p_translation);
	Transform3D translated(const Vector3 &p_translation) const;

	const Basis &get_basis() const { return basis; }
	void set_basis(const Basis &p_basis) { basis = p_basis; }

	const Vector3 &get_origin() const { return origin; }
	void set_origin(const Vector3 &p_origin) { origin = p_origin; }

	void orthonormalize();
	Transform3D orthonormalized() const;
	bool is_equal_approx(const Transform3D &p_transform) const;

	bool operator==(const Transform3D &p_transform) const;
	bool operator!=(const Transform3D &p_transform) const;

	inline Vector3 xform(const Vector3 &p_vector) const;
	inline Vector3 xform_inv(const Vector3 &p_vector) const;

	inline Plane xform(const Plane &p_plane) const;
	inline Plane xform_inv(const Plane &p_plane) const;

	inline AABB xform(const AABB &p_aabb) const;
	inline AABB xform_inv(const AABB &p_aabb) const;

	inline PackedVector3Array xform(const PackedVector3Array &p_array) const;
	inline PackedVector3Array xform_inv(const PackedVector3Array &p_array) const;

	void operator*=(const Transform3D &p_transform);
	Transform3D operator*(const Transform3D &p_transform) const;

	Transform3D interpolate_with(const Transform3D &p_transform, real_t p_c) const;

	inline Transform3D inverse_xform(const Transform3D &t) const {
		Vector3 v = t.origin - origin;
		return Transform3D(basis.transpose_xform(t.basis),
				basis.xform(v));
	}

	void set(real_t xx, real_t xy, real_t xz, real_t yx, real_t yy, real_t yz, real_t zx, real_t zy, real_t zz, real_t tx, real_t ty, real_t tz) {
		basis.set(xx, xy, xz, yx, yy, yz, zx, zy, zz);
		origin.x = tx;
		origin.y = ty;
		origin.z = tz;
	}

	operator String() const;

	Transform3D() {}
	Transform3D(const Basis &p_basis, const Vector3 &p_origin = Vector3());
	Transform3D(const Vector3 &p_x, const Vector3 &p_y, const Vector3 &p_z, const Vector3 &p_origin);
	Transform3D(real_t xx, real_t xy, real_t xz, real_t yx, real_t yy, real_t yz, real_t zx, real_t zy, real_t zz, real_t ox, real_t oy, real_t oz);
};

inline Vector3 Transform3D::xform(const Vector3 &p_vector) const {
	return Vector3(
			basis[0].dot(p_vector) + origin.x,
			basis[1].dot(p_vector) + origin.y,
			basis[2].dot(p_vector) + origin.z);
}

inline Vector3 Transform3D::xform_inv(const Vector3 &p_vector) const {
	Vector3 v = p_vector - origin;

	return Vector3(
			(basis.elements[0][0] * v.x) + (basis.elements[1][0] * v.y) + (basis.elements[2][0] * v.z),
			(basis.elements[0][1] * v.x) + (basis.elements[1][1] * v.y) + (basis.elements[2][1] * v.z),
			(basis.elements[0][2] * v.x) + (basis.elements[1][2] * v.y) + (basis.elements[2][2] * v.z));
}

inline Plane Transform3D::xform(const Plane &p_plane) const {
	Vector3 point = p_plane.normal * p_plane.d;
	Vector3 point_dir = point + p_plane.normal;
	point = xform(point);
	point_dir = xform(point_dir);

	Vector3 normal = point_dir - point;
	normal.normalize();
	real_t d = normal.dot(point);

	return Plane(normal, d);
}

inline Plane Transform3D::xform_inv(const Plane &p_plane) const {
	Vector3 point = p_plane.normal * p_plane.d;
	Vector3 point_dir = point + p_plane.normal;
	point = xform_inv(point);
	point_dir = xform_inv(point_dir);

	Vector3 normal = point_dir - point;
	normal.normalize();
	real_t d = normal.dot(point);

	return Plane(normal, d);
}

inline AABB Transform3D::xform(const AABB &p_aabb) const {
	/* http://dev.theomader.com/transform-bounding-boxes/ */
	Vector3 min = p_aabb.position;
	Vector3 max = p_aabb.position + p_aabb.size;
	Vector3 tmin, tmax;
	for (int i = 0; i < 3; i++) {
		tmin[i] = tmax[i] = origin[i];
		for (int j = 0; j < 3; j++) {
			real_t e = basis[i][j] * min[j];
			real_t f = basis[i][j] * max[j];
			if (e < f) {
				tmin[i] += e;
				tmax[i] += f;
			} else {
				tmin[i] += f;
				tmax[i] += e;
			}
		}
	}
	AABB r_aabb;
	r_aabb.position = tmin;
	r_aabb.size = tmax - tmin;
	return r_aabb;
}

inline AABB Transform3D::xform_inv(const AABB &p_aabb) const {
	/* define vertices */
	Vector3 vertices[8] = {
		Vector3(p_aabb.position.x + p_aabb.size.x, p_aabb.position.y + p_aabb.size.y, p_aabb.position.z + p_aabb.size.z),
		Vector3(p_aabb.position.x + p_aabb.size.x, p_aabb.position.y + p_aabb.size.y, p_aabb.position.z),
		Vector3(p_aabb.position.x + p_aabb.size.x, p_aabb.position.y, p_aabb.position.z + p_aabb.size.z),
		Vector3(p_aabb.position.x + p_aabb.size.x, p_aabb.position.y, p_aabb.position.z),
		Vector3(p_aabb.position.x, p_aabb.position.y + p_aabb.size.y, p_aabb.position.z + p_aabb.size.z),
		Vector3(p_aabb.position.x, p_aabb.position.y + p_aabb.size.y, p_aabb.position.z),
		Vector3(p_aabb.position.x, p_aabb.position.y, p_aabb.position.z + p_aabb.size.z),
		Vector3(p_aabb.position.x, p_aabb.position.y, p_aabb.position.z)
	};

	AABB ret;

	ret.position = xform_inv(vertices[0]);

	for (int i = 1; i < 8; i++) {
		ret.expand_to(xform_inv(vertices[i]));
	}

	return ret;
}

PackedVector3Array Transform3D::xform(const PackedVector3Array &p_array) const {
	PackedVector3Array array;
	array.resize(p_array.size());

	for (int i = 0; i < p_array.size(); ++i) {
		array[i] = xform(p_array[i]);
	}
	return array;
}

PackedVector3Array Transform3D::xform_inv(const PackedVector3Array &p_array) const {
	PackedVector3Array array;
	array.resize(p_array.size());

	for (int i = 0; i < p_array.size(); ++i) {
		array[i] = xform_inv(p_array[i]);
	}
	return array;
}

} // namespace godot

#endif // GODOT_TRANSFORM_HPP
