/*************************************************************************/
/*  color_names.inc.hpp                                                  */
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

namespace godot {

struct NamedColor {
	const char *name;
	Color color;
};

static NamedColor named_colors[] = {
	{ "aliceblue", Color(0.94, 0.97, 1.00) },
	{ "antiquewhite", Color(0.98, 0.92, 0.84) },
	{ "aqua", Color(0.00, 1.00, 1.00) },
	{ "aquamarine", Color(0.50, 1.00, 0.83) },
	{ "azure", Color(0.94, 1.00, 1.00) },
	{ "beige", Color(0.96, 0.96, 0.86) },
	{ "bisque", Color(1.00, 0.89, 0.77) },
	{ "black", Color(0.00, 0.00, 0.00) },
	{ "blanchedalmond", Color(1.00, 0.92, 0.80) },
	{ "blue", Color(0.00, 0.00, 1.00) },
	{ "blueviolet", Color(0.54, 0.17, 0.89) },
	{ "brown", Color(0.65, 0.16, 0.16) },
	{ "burlywood", Color(0.87, 0.72, 0.53) },
	{ "cadetblue", Color(0.37, 0.62, 0.63) },
	{ "chartreuse", Color(0.50, 1.00, 0.00) },
	{ "chocolate", Color(0.82, 0.41, 0.12) },
	{ "coral", Color(1.00, 0.50, 0.31) },
	{ "cornflower", Color(0.39, 0.58, 0.93) },
	{ "cornsilk", Color(1.00, 0.97, 0.86) },
	{ "crimson", Color(0.86, 0.08, 0.24) },
	{ "cyan", Color(0.00, 1.00, 1.00) },
	{ "darkblue", Color(0.00, 0.00, 0.55) },
	{ "darkcyan", Color(0.00, 0.55, 0.55) },
	{ "darkgoldenrod", Color(0.72, 0.53, 0.04) },
	{ "darkgray", Color(0.66, 0.66, 0.66) },
	{ "darkgreen", Color(0.00, 0.39, 0.00) },
	{ "darkkhaki", Color(0.74, 0.72, 0.42) },
	{ "darkmagenta", Color(0.55, 0.00, 0.55) },
	{ "darkolivegreen", Color(0.33, 0.42, 0.18) },
	{ "darkorange", Color(1.00, 0.55, 0.00) },
	{ "darkorchid", Color(0.60, 0.20, 0.80) },
	{ "darkred", Color(0.55, 0.00, 0.00) },
	{ "darksalmon", Color(0.91, 0.59, 0.48) },
	{ "darkseagreen", Color(0.56, 0.74, 0.56) },
	{ "darkslateblue", Color(0.28, 0.24, 0.55) },
	{ "darkslategray", Color(0.18, 0.31, 0.31) },
	{ "darkturquoise", Color(0.00, 0.81, 0.82) },
	{ "darkviolet", Color(0.58, 0.00, 0.83) },
	{ "deeppink", Color(1.00, 0.08, 0.58) },
	{ "deepskyblue", Color(0.00, 0.75, 1.00) },
	{ "dimgray", Color(0.41, 0.41, 0.41) },
	{ "dodgerblue", Color(0.12, 0.56, 1.00) },
	{ "firebrick", Color(0.70, 0.13, 0.13) },
	{ "floralwhite", Color(1.00, 0.98, 0.94) },
	{ "forestgreen", Color(0.13, 0.55, 0.13) },
	{ "fuchsia", Color(1.00, 0.00, 1.00) },
	{ "gainsboro", Color(0.86, 0.86, 0.86) },
	{ "ghostwhite", Color(0.97, 0.97, 1.00) },
	{ "gold", Color(1.00, 0.84, 0.00) },
	{ "goldenrod", Color(0.85, 0.65, 0.13) },
	{ "gray", Color(0.75, 0.75, 0.75) },
	{ "green", Color(0.00, 1.00, 0.00) },
	{ "greenyellow", Color(0.68, 1.00, 0.18) },
	{ "honeydew", Color(0.94, 1.00, 0.94) },
	{ "hotpink", Color(1.00, 0.41, 0.71) },
	{ "indianred", Color(0.80, 0.36, 0.36) },
	{ "indigo", Color(0.29, 0.00, 0.51) },
	{ "ivory", Color(1.00, 1.00, 0.94) },
	{ "khaki", Color(0.94, 0.90, 0.55) },
	{ "lavender", Color(0.90, 0.90, 0.98) },
	{ "lavenderblush", Color(1.00, 0.94, 0.96) },
	{ "lawngreen", Color(0.49, 0.99, 0.00) },
	{ "lemonchiffon", Color(1.00, 0.98, 0.80) },
	{ "lightblue", Color(0.68, 0.85, 0.90) },
	{ "lightcoral", Color(0.94, 0.50, 0.50) },
	{ "lightcyan", Color(0.88, 1.00, 1.00) },
	{ "lightgoldenrod", Color(0.98, 0.98, 0.82) },
	{ "lightgray", Color(0.83, 0.83, 0.83) },
	{ "lightgreen", Color(0.56, 0.93, 0.56) },
	{ "lightpink", Color(1.00, 0.71, 0.76) },
	{ "lightsalmon", Color(1.00, 0.63, 0.48) },
	{ "lightseagreen", Color(0.13, 0.70, 0.67) },
	{ "lightskyblue", Color(0.53, 0.81, 0.98) },
	{ "lightslategray", Color(0.47, 0.53, 0.60) },
	{ "lightsteelblue", Color(0.69, 0.77, 0.87) },
	{ "lightyellow", Color(1.00, 1.00, 0.88) },
	{ "lime", Color(0.00, 1.00, 0.00) },
	{ "limegreen", Color(0.20, 0.80, 0.20) },
	{ "linen", Color(0.98, 0.94, 0.90) },
	{ "magenta", Color(1.00, 0.00, 1.00) },
	{ "maroon", Color(0.69, 0.19, 0.38) },
	{ "mediumaquamarine", Color(0.40, 0.80, 0.67) },
	{ "mediumblue", Color(0.00, 0.00, 0.80) },
	{ "mediumorchid", Color(0.73, 0.33, 0.83) },
	{ "mediumpurple", Color(0.58, 0.44, 0.86) },
	{ "mediumseagreen", Color(0.24, 0.70, 0.44) },
	{ "mediumslateblue", Color(0.48, 0.41, 0.93) },
	{ "mediumspringgreen", Color(0.00, 0.98, 0.60) },
	{ "mediumturquoise", Color(0.28, 0.82, 0.80) },
	{ "mediumvioletred", Color(0.78, 0.08, 0.52) },
	{ "midnightblue", Color(0.10, 0.10, 0.44) },
	{ "mintcream", Color(0.96, 1.00, 0.98) },
	{ "mistyrose", Color(1.00, 0.89, 0.88) },
	{ "moccasin", Color(1.00, 0.89, 0.71) },
	{ "navajowhite", Color(1.00, 0.87, 0.68) },
	{ "navyblue", Color(0.00, 0.00, 0.50) },
	{ "oldlace", Color(0.99, 0.96, 0.90) },
	{ "olive", Color(0.50, 0.50, 0.00) },
	{ "olivedrab", Color(0.42, 0.56, 0.14) },
	{ "orange", Color(1.00, 0.65, 0.00) },
	{ "orangered", Color(1.00, 0.27, 0.00) },
	{ "orchid", Color(0.85, 0.44, 0.84) },
	{ "palegoldenrod", Color(0.93, 0.91, 0.67) },
	{ "palegreen", Color(0.60, 0.98, 0.60) },
	{ "paleturquoise", Color(0.69, 0.93, 0.93) },
	{ "palevioletred", Color(0.86, 0.44, 0.58) },
	{ "papayawhip", Color(1.00, 0.94, 0.84) },
	{ "peachpuff", Color(1.00, 0.85, 0.73) },
	{ "peru", Color(0.80, 0.52, 0.25) },
	{ "pink", Color(1.00, 0.75, 0.80) },
	{ "plum", Color(0.87, 0.63, 0.87) },
	{ "powderblue", Color(0.69, 0.88, 0.90) },
	{ "purple", Color(0.63, 0.13, 0.94) },
	{ "rebeccapurple", Color(0.40, 0.20, 0.60) },
	{ "red", Color(1.00, 0.00, 0.00) },
	{ "rosybrown", Color(0.74, 0.56, 0.56) },
	{ "royalblue", Color(0.25, 0.41, 0.88) },
	{ "saddlebrown", Color(0.55, 0.27, 0.07) },
	{ "salmon", Color(0.98, 0.50, 0.45) },
	{ "sandybrown", Color(0.96, 0.64, 0.38) },
	{ "seagreen", Color(0.18, 0.55, 0.34) },
	{ "seashell", Color(1.00, 0.96, 0.93) },
	{ "sienna", Color(0.63, 0.32, 0.18) },
	{ "silver", Color(0.75, 0.75, 0.75) },
	{ "skyblue", Color(0.53, 0.81, 0.92) },
	{ "slateblue", Color(0.42, 0.35, 0.80) },
	{ "slategray", Color(0.44, 0.50, 0.56) },
	{ "snow", Color(1.00, 0.98, 0.98) },
	{ "springgreen", Color(0.00, 1.00, 0.50) },
	{ "steelblue", Color(0.27, 0.51, 0.71) },
	{ "tan", Color(0.82, 0.71, 0.55) },
	{ "teal", Color(0.00, 0.50, 0.50) },
	{ "thistle", Color(0.85, 0.75, 0.85) },
	{ "tomato", Color(1.00, 0.39, 0.28) },
	{ "transparent", Color(1.00, 1.00, 1.00, 0.00) },
	{ "turquoise", Color(0.25, 0.88, 0.82) },
	{ "violet", Color(0.93, 0.51, 0.93) },
	{ "webgray", Color(0.50, 0.50, 0.50) },
	{ "webgreen", Color(0.00, 0.50, 0.00) },
	{ "webmaroon", Color(0.50, 0.00, 0.00) },
	{ "webpurple", Color(0.50, 0.00, 0.50) },
	{ "wheat", Color(0.96, 0.87, 0.70) },
	{ "white", Color(1.00, 1.00, 1.00) },
	{ "whitesmoke", Color(0.96, 0.96, 0.96) },
	{ "yellow", Color(1.00, 1.00, 0.00) },
	{ "yellowgreen", Color(0.60, 0.80, 0.20) },
	{ nullptr, Color() },
};

} // namespace godot
