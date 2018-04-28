#pragma once

#include <vector>
#include <iostream>
#include <glad/glad.h>
#include "../math/math.h"
#include "../utils/fileutils.h"

namespace vingin
{
	namespace graphics
	{
		class Shader
		{
		public:
			Shader(const char *vertPath, const char *fragPath);
			~Shader();

			void enable();
			void disable();

			void setUniform1f(const char* name, float value) const;
			void setUniform1i(const char* name, int value) const;
			void setUniform2f(const char* name, const math::vec2 &vector) const;
			void setUniform3f(const char* name, const math::vec3 &vector) const;
			void setUniform4f(const char* name, const math::vec4 &vector) const;
			void setUniformMat4(const char* name, const math::mat4 &matrix) const;
		private:
			GLuint load();

			GLuint m_ShaderID;

			const char *m_VertPath, *m_FragPath;
		};
	}
}