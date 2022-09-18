/*************************************************************************/
/*  math.hpp                                                             */
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

#ifndef GODOT_MATH_H
#define GODOT_MATH_H

#include <godot_cpp/core/defs.hpp>

#include <godot/gdnative_interface.h>

#include <cmath>

namespace godot {
namespace Math {

// This epsilon should match the one used by Godot for consistency.
// Using `f` when `real_t` is float.
#define CMP_EPSILON 0.00001f
#define CMP_EPSILON2 (CMP_EPSILON * CMP_EPSILON)

// This epsilon is for values related to a unit size (scalar or vector len).
#ifdef PRECISE_MATH_CHECKS
#define UNIT_EPSILON 0.00001
#else
// Tolerate some more floating point error normally.
#define UNIT_EPSILON 0.001
#endif

#define Math_SQRT12 0.7071067811865475244008443621048490
#define Math_SQRT2 1.4142135623730950488016887242
#define Math_LN2 0.6931471805599453094172321215
#define Math_PI 3.1415926535897932384626433833
#define Math_TAU 6.2831853071795864769252867666
#define Math_E 2.7182818284590452353602874714
#define Math_INF INFINITY
#define Math_NAN NAN

// Windows badly defines a lot of stuff we'll never use. Undefine it.
#ifdef _WIN32
#undef MIN // override standard definition
#undef MAX // override standard definition
#undef CLAMP // override standard definition
#endif

// Generic ABS function, for math uses please use Math::abs.
#ifndef ABS
#define ABS(m_v) (((m_v) < 0) ? (-(m_v)) : (m_v))
#endif

#ifndef SIGN
#define SIGN(m_v) (((m_v) == 0) ? (0.0) : (((m_v) < 0) ? (-1.0) : (+1.0)))
#endif

#ifndef MIN
#define MIN(m_a, m_b) (((m_a) < (m_b)) ? (m_a) : (m_b))
#endif

#ifndef MAX
#define MAX(m_a, m_b) (((m_a) > (m_b)) ? (m_a) : (m_b))
#endif

#ifndef CLAMP
#define CLAMP(m_a, m_min, m_max) (((m_a) < (m_min)) ? (m_min) : (((m_a) > (m_max)) ? m_max : m_a))
#endif

// Functions reproduced as in Godot's source code `math_funcs.h`.
// Some are overloads to automatically support changing real_t into either double or float in the way Godot does.

inline double fmod(double p_x, double p_y) {
	return ::fmod(p_x, p_y);
}
inline float fmod(float p_x, float p_y) {
	return ::fmodf(p_x, p_y);
}

inline double fposmod(double p_x, double p_y) {
	double value = Math::fmod(p_x, p_y);
	if ((value < 0 && p_y > 0) || (value > 0 && p_y < 0)) {
		value += p_y;
	}
	value += 0.0;
	return value;
}
inline float fposmod(float p_x, float p_y) {
	float value = Math::fmod(p_x, p_y);
	if ((value < 0 && p_y > 0) || (value > 0 && p_y < 0)) {
		value += p_y;
	}
	value += 0.0;
	return value;
}

inline float fposmodp(float p_x, float p_y) {
	float value = Math::fmod(p_x, p_y);
	if (value < 0) {
		value += p_y;
	}
	value += 0.0;
	return value;
}
inline double fposmodp(double p_x, double p_y) {
	double value = Math::fmod(p_x, p_y);
	if (value < 0) {
		value += p_y;
	}
	value += 0.0;
	return value;
}

inline double floor(double p_x) {
	return ::floor(p_x);
}
inline float floor(float p_x) {
	return ::floorf(p_x);
}

inline double ceil(double p_x) {
	return ::ceil(p_x);
}
inline float ceil(float p_x) {
	return ::ceilf(p_x);
}

inline double exp(double p_x) {
	return ::exp(p_x);
}
inline float exp(float p_x) {
	return ::expf(p_x);
}

inline double sin(double p_x) {
	return ::sin(p_x);
}
inline float sin(float p_x) {
	return ::sinf(p_x);
}

inline double cos(double p_x) {
	return ::cos(p_x);
}
inline float cos(float p_x) {
	return ::cosf(p_x);
}

inline double tan(double p_x) {
	return ::tan(p_x);
}
inline float tan(float p_x) {
	return ::tanf(p_x);
}

inline double sinh(double p_x) {
	return ::sinh(p_x);
}
inline float sinh(float p_x) {
	return ::sinhf(p_x);
}

inline float sinc(float p_x) {
	return p_x == 0 ? 1 : ::sin(p_x) / p_x;
}
inline double sinc(double p_x) {
	return p_x == 0 ? 1 : ::sin(p_x) / p_x;
}

inline float sincn(float p_x) {
	return (float)sinc(Math_PI * p_x);
}
inline double sincn(double p_x) {
	return sinc(Math_PI * p_x);
}

inline double cosh(double p_x) {
	return ::cosh(p_x);
}
inline float cosh(float p_x) {
	return ::coshf(p_x);
}

inline double tanh(double p_x) {
	return ::tanh(p_x);
}
inline float tanh(float p_x) {
	return ::tanhf(p_x);
}

inline double asin(double p_x) {
	return ::asin(p_x);
}
inline float asin(float p_x) {
	return ::asinf(p_x);
}

inline double acos(double p_x) {
	return ::acos(p_x);
}
inline float acos(float p_x) {
	return ::acosf(p_x);
}

inline double atan(double p_x) {
	return ::atan(p_x);
}
inline float atan(float p_x) {
	return ::atanf(p_x);
}

inline double atan2(double p_y, double p_x) {
	return ::atan2(p_y, p_x);
}
inline float atan2(float p_y, float p_x) {
	return ::atan2f(p_y, p_x);
}

inline double sqrt(double p_x) {
	return ::sqrt(p_x);
}
inline float sqrt(float p_x) {
	return ::sqrtf(p_x);
}

inline double pow(double p_x, double p_y) {
	return ::pow(p_x, p_y);
}
inline float pow(float p_x, float p_y) {
	return ::powf(p_x, p_y);
}

inline double log(double p_x) {
	return ::log(p_x);
}
inline float log(float p_x) {
	return ::logf(p_x);
}

inline float lerp(float minv, float maxv, float t) {
	return minv + t * (maxv - minv);
}
inline double lerp(double minv, double maxv, double t) {
	return minv + t * (maxv - minv);
}

inline double lerp_angle(double p_from, double p_to, double p_weight) {
	double difference = fmod(p_to - p_from, Math_TAU);
	double distance = fmod(2.0 * difference, Math_TAU) - difference;
	return p_from + distance * p_weight;
}
inline float lerp_angle(float p_from, float p_to, float p_weight) {
	float difference = fmod(p_to - p_from, (float)Math_TAU);
	float distance = fmod(2.0f * difference, (float)Math_TAU) - difference;
	return p_from + distance * p_weight;
}

inline double cubic_interpolate(double p_from, double p_to, double p_pre, double p_post, double p_weight) {
	return 0.5 *
		   ((p_from * 2.0) +
				   (-p_pre + p_to) * p_weight +
				   (2.0 * p_pre - 5.0 * p_from + 4.0 * p_to - p_post) * (p_weight * p_weight) +
				   (-p_pre + 3.0 * p_from - 3.0 * p_to + p_post) * (p_weight * p_weight * p_weight));
}
inline float cubic_interpolate(float p_from, float p_to, float p_pre, float p_post, float p_weight) {
	return 0.5f *
		   ((p_from * 2.0f) +
				   (-p_pre + p_to) * p_weight +
				   (2.0f * p_pre - 5.0f * p_from + 4.0f * p_to - p_post) * (p_weight * p_weight) +
				   (-p_pre + 3.0f * p_from - 3.0f * p_to + p_post) * (p_weight * p_weight * p_weight));
}

template <typename T>
inline T clamp(T x, T minv, T maxv) {
	if (x < minv) {
		return minv;
	}
	if (x > maxv) {
		return maxv;
	}
	return x;
}

template <typename T>
inline T min(T a, T b) {
	return a < b ? a : b;
}

template <typename T>
inline T max(T a, T b) {
	return a > b ? a : b;
}

template <typename T>
inline T sign(T x) {
	return static_cast<T>(x < 0 ? -1 : 1);
}

template <typename T>
inline T abs(T x) {
	return std::abs(x);
}

inline double deg2rad(double p_y) {
	return p_y * Math_PI / 180.0;
}
inline float deg2rad(float p_y) {
	return p_y * static_cast<float>(Math_PI) / 180.f;
}

inline double rad2deg(double p_y) {
	return p_y * 180.0 / Math_PI;
}
inline float rad2deg(float p_y) {
	return p_y * 180.f / static_cast<float>(Math_PI);
}

inline double inverse_lerp(double p_from, double p_to, double p_value) {
	return (p_value - p_from) / (p_to - p_from);
}
inline float inverse_lerp(float p_from, float p_to, float p_value) {
	return (p_value - p_from) / (p_to - p_from);
}

inline double range_lerp(double p_value, double p_istart, double p_istop, double p_ostart, double p_ostop) {
	return Math::lerp(p_ostart, p_ostop, Math::inverse_lerp(p_istart, p_istop, p_value));
}
inline float range_lerp(float p_value, float p_istart, float p_istop, float p_ostart, float p_ostop) {
	return Math::lerp(p_ostart, p_ostop, Math::inverse_lerp(p_istart, p_istop, p_value));
}

inline bool is_equal_approx(real_t a, real_t b) {
	// Check for exact equality first, required to handle "infinity" values.
	if (a == b) {
		return true;
	}
	// Then check for approximate equality.
	real_t tolerance = CMP_EPSILON * std::abs(a);
	if (tolerance < CMP_EPSILON) {
		tolerance = CMP_EPSILON;
	}
	return std::abs(a - b) < tolerance;
}

inline bool is_equal_approx(real_t a, real_t b, real_t tolerance) {
	// Check for exact equality first, required to handle "infinity" values.
	if (a == b) {
		return true;
	}
	// Then check for approximate equality.
	return std::abs(a - b) < tolerance;
}

inline bool is_zero_approx(real_t s) {
	return std::abs(s) < CMP_EPSILON;
}

inline double smoothstep(double p_from, double p_to, double p_weight) {
	if (is_equal_approx(static_cast<real_t>(p_from), static_cast<real_t>(p_to))) {
		return p_from;
	}
	double x = clamp((p_weight - p_from) / (p_to - p_from), 0.0, 1.0);
	return x * x * (3.0 - 2.0 * x);
}
inline float smoothstep(float p_from, float p_to, float p_weight) {
	if (is_equal_approx(p_from, p_to)) {
		return p_from;
	}
	float x = clamp((p_weight - p_from) / (p_to - p_from), 0.0f, 1.0f);
	return x * x * (3.0f - 2.0f * x);
}

inline double move_toward(double p_from, double p_to, double p_delta) {
	return std::abs(p_to - p_from) <= p_delta ? p_to : p_from + sign(p_to - p_from) * p_delta;
}

inline float move_toward(float p_from, float p_to, float p_delta) {
	return std::abs(p_to - p_from) <= p_delta ? p_to : p_from + sign(p_to - p_from) * p_delta;
}

inline double linear2db(double p_linear) {
	return log(p_linear) * 8.6858896380650365530225783783321;
}
inline float linear2db(float p_linear) {
	return log(p_linear) * 8.6858896380650365530225783783321f;
}

inline double db2linear(double p_db) {
	return exp(p_db * 0.11512925464970228420089957273422);
}
inline float db2linear(float p_db) {
	return exp(p_db * 0.11512925464970228420089957273422f);
}

inline double round(double p_val) {
	return (p_val >= 0) ? floor(p_val + 0.5) : -floor(-p_val + 0.5);
}
inline float round(float p_val) {
	return (p_val >= 0) ? floor(p_val + 0.5f) : -floor(-p_val + 0.5f);
}

inline int64_t wrapi(int64_t value, int64_t min, int64_t max) {
	int64_t range = max - min;
	return range == 0 ? min : min + ((((value - min) % range) + range) % range);
}

inline float wrapf(real_t value, real_t min, real_t max) {
	const real_t range = max - min;
	return is_zero_approx(range) ? min : value - (range * floor((value - min) / range));
}

inline float stepify(float p_value, float p_step) {
	if (p_step != 0) {
		p_value = floor(p_value / p_step + 0.5f) * p_step;
	}
	return p_value;
}
inline double stepify(double p_value, double p_step) {
	if (p_step != 0) {
		p_value = floor(p_value / p_step + 0.5) * p_step;
	}
	return p_value;
}

inline unsigned int next_power_of_2(unsigned int x) {
	if (x == 0)
		return 0;

	--x;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;

	return ++x;
}

// This function should be as fast as possible and rounding mode should not matter.
inline int fast_ftoi(float a) {
	static int b;

#if (defined(_WIN32_WINNT) && _WIN32_WINNT >= 0x0603) || WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP // windows 8 phone?
	b = (int)((a > 0.0) ? (a + 0.5) : (a - 0.5));

#elif defined(_MSC_VER) && _MSC_VER < 1800
	__asm fld a __asm fistp b
	/*#elif defined( __GNUC__ ) && ( defined( __i386__ ) || defined( __x86_64__ ) )
	// use AT&T inline assembly style, document that
	// we use memory as output (=m) and input (m)
	__asm__ __volatile__ (
	"flds %1        \n\t"
	"fistpl %0      \n\t"
	: "=m" (b)
	: "m" (a));*/

#else
	b = lrintf(a); // assuming everything but msvc 2012 or earlier has lrint
#endif
	return b;
}

inline double snapped(double p_value, double p_step) {
	if (p_step != 0) {
		p_value = Math::floor(p_value / p_step + 0.5) * p_step;
	}
	return p_value;
}

} // namespace Math
} // namespace godot

#endif // GODOT_MATH_H
