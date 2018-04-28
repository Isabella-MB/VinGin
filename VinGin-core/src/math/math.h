#pragma once

#define _USE_MATH_DEFINES

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

namespace vingin
{
	namespace math
	{
		class MathFunc
		{
		public:
			static float toRadians(float degrees)
			{
				return degrees * (M_PI / 180.0f);
			}
		private:
			MathFunc();
		};
	}
}