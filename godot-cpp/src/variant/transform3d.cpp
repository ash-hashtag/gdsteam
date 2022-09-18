/*************************************************************************/
/*  transform3d.cpp                                                      */
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

#include <godot_cpp/variant/transform3d.hpp>

#include <godot_cpp/variant/string.hpp>

namespace godot {

void Transform3D::affine_invert() {
	basis.invert();
	origin = basis.xform(-origin);
}

Transform3D Transform3D::affine_inverse() const {
	Transform3D ret = *this;
	ret.affine_invert();
	return ret;
}

void Transform3D::invert() {
	basis.transpose();
	origin = basis.xform(-origin);
}

Transform3D Transform3D::inverse() const {
	// FIXME: this function assumes the basis is a rotation matrix, with no scaling.
	// Transform3D::affine_inverse can handle matrices with scaling, so GDScript should eventually use that.
	Transform3D ret = *this;
	ret.invert();
	return ret;
}

void Transform3D::rotate(const Vector3 &p_axis, real_t p_phi) {
	*this = rotated(p_axis, p_phi);
}

Transform3D Transform3D::rotated(const Vector3 &p_axis, real_t p_phi) const {
	return Transform3D(Basis(p_axis, p_phi), Vector3()) * (*this);
}

void Transform3D::rotate_basis(const Vector3 &p_axis, real_t p_phi) {
	basis.rotate(p_axis, p_phi);
}

Transform3D Transform3D::looking_at(const Vector3 &p_target, const Vector3 &p_up) const {
	Transform3D t = *this;
	t.set_look_at(origin, p_target, p_up);
	return t;
}

void Transform3D::set_look_at(const Vector3 &p_eye, const Vector3 &p_target, const Vector3 &p_up) {
#ifdef MATH_CHECKS
	ERR_FAIL_COND(p_eye == p_target);
	ERR_FAIL_COND(p_up.length() == 0);
#endif
	// RefCounted: MESA source code
	Vector3 v_x, v_y, v_z;

	/* Make rotation matrix */

	/* Z vector */
	v_z = p_eye - p_target;

	v_z.normalize();

	v_y = p_up;

	v_x = v_y.cross(v_z);
#ifdef MATH_CHECKS
	ERR_FAIL_COND(v_x.length() == 0);
#endif

	/* Recompute Y = Z cross X */
	v_y = v_z.cross(v_x);

	v_x.normalize();
	v_y.normalize();

	basis.set(v_x, v_y, v_z);

	origin = p_eye;
}

Transform3D Transform3D::interpolate_with(const Transform3D &p_transform, real_t p_c) const {
	/* not sure if very "efficient" but good enough? */

	Vector3 src_scale = basis.get_scale();
	Quaternion src_rot = basis.get_rotation_quat();
	Vector3 src_loc = origin;

	Vector3 dst_scale = p_transform.basis.get_scale();
	Quaternion dst_rot = p_transform.basis.get_rotation_quat();
	Vector3 dst_loc = p_transform.origin;

	Transform3D interp;
	interp.basis.set_quat_scale(src_rot.slerp(dst_rot, p_c).normalized(), src_scale.lerp(dst_scale, p_c));
	interp.origin = src_loc.lerp(dst_loc, p_c);

	return interp;
}

void Transform3D::scale(const Vector3 &p_scale) {
	basis.scale(p_scale);
	origin *= p_scale;
}

Transform3D Transform3D::scaled(const Vector3 &p_scale) const {
	Transform3D t = *this;
	t.scale(p_scale);
	return t;
}

void Transform3D::scale_basis(const Vector3 &p_scale) {
	basis.scale(p_scale);
}

void Transform3D::translate(real_t p_tx, real_t p_ty, real_t p_tz) {
	translate(Vector3(p_tx, p_ty, p_tz));
}

void Transform3D::translate(const Vector3 &p_translation) {
	for (int i = 0; i < 3; i++) {
		origin[i] += basis[i].dot(p_translation);
	}
}

Transform3D Transform3D::translated(const Vector3 &p_translation) const {
	Transform3D t = *this;
	t.translate(p_translation);
	return t;
}

void Transform3D::orthonormalize() {
	basis.orthonormalize();
}

Transform3D Transform3D::orthonormalized() const {
	Transform3D _copy = *this;
	_copy.orthonormalize();
	return _copy;
}

bool Transform3D::is_equal_approx(const Transform3D &p_transform) const {
	return basis.is_equal_approx(p_transform.basis) && origin.is_equal_approx(p_transform.origin);
}

bool Transform3D::operator==(const Transform3D &p_transform) const {
	return (basis == p_transform.basis && origin == p_transform.origin);
}

bool Transform3D::operator!=(const Transform3D &p_transform) const {
	return (basis != p_transform.basis || origin != p_transform.origin);
}

void Transform3D::operator*=(const Transform3D &p_transform) {
	origin = xform(p_transform.origin);
	basis *= p_transform.basis;
}

Transform3D Transform3D::operator*(const Transform3D &p_transform) const {
	Transform3D t = *this;
	t *= p_transform;
	return t;
}

Transform3D::operator String() const {
	return basis.operator String() + " - " + origin.operator String();
}

Transform3D::Transform3D(const Basis &p_basis, const Vector3 &p_origin) :
		basis(p_basis),
		origin(p_origin) {
}

Transform3D::Transform3D(const Vector3 &p_x, const Vector3 &p_y, const Vector3 &p_z, const Vector3 &p_origin) :
		origin(p_origin) {
	basis.set_axis(0, p_x);
	basis.set_axis(1, p_y);
	basis.set_axis(2, p_z);
}

Transform3D::Transform3D(real_t xx, real_t xy, real_t xz, real_t yx, real_t yy, real_t yz, real_t zx, real_t zy, real_t zz, real_t ox, real_t oy, real_t oz) {
	basis = Basis(xx, xy, xz, yx, yy, yz, zx, zy, zz);
	origin = Vector3(ox, oy, oz);
}

} // namespace godot
