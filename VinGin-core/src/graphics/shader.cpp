#include "shader.h"

namespace vingin
{
	namespace graphics
	{
		Shader::Shader(const char *vertPath, const char *fragPath) : m_VertPath(vertPath), m_FragPath(fragPath)
		{
			m_ShaderID = load();
		}

		Shader::~Shader()
		{
			glDeleteProgram(m_ShaderID);
		}

		GLuint Shader::load()
		{
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertSourceString = FileUtil::read_file(m_VertPath);
			std::string fragSourceString = FileUtil::read_file(m_FragPath);

			const char* vertSource = vertSourceString.c_str();
			const char* fragSource = fragSourceString.c_str();

			glShaderSource(vertex, 1, &vertSource, NULL);
			glCompileShader(vertex);

			GLint result;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);

				std::cout << "Failed to compile vertex shader!" << std::endl << &error[0] << std::endl;
				glDeleteShader(vertex);
				return 0;
			}

			glShaderSource(fragment, 1, &fragSource, NULL);
			glCompileShader(fragment);

			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);

				std::cout << "Failed to compile fragment shader!" << std::endl << &error[0] << std::endl;
				glDeleteShader(fragment);
				return 0;
			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return program;
		}

		void Shader::enable()
		{
			glUseProgram(m_ShaderID);
		}

		void Shader::disable()
		{
			glUseProgram(0);
		}

		void Shader::setUniform1f(const char* name, float value) const
		{
			glUniform1f(glGetUniformLocation(m_ShaderID, name), value);
		}

		void Shader::setUniform1i(const char* name, int value) const
		{
			glUniform1i(glGetUniformLocation(m_ShaderID, name), value);
		}

		void Shader::setUniform2f(const char* name, const math::vec2 &vector) const
		{
			glUniform2f(glGetUniformLocation(m_ShaderID, name), vector.x, vector.y);
		}

		void Shader::setUniform3f(const char* name, const math::vec3 &vector) const
		{
			glUniform3f(glGetUniformLocation(m_ShaderID, name), vector.x, vector.y, vector.z);
		}

		void Shader::setUniform4f(const char* name, const math::vec4 &vector) const
		{
			glUniform4f(glGetUniformLocation(m_ShaderID, name), vector.x, vector.y, vector.z, vector.w);
		}

		void Shader::setUniformMat4(const char* name, const math::mat4 &matrix) const
		{
			glUniformMatrix4fv(glGetUniformLocation(m_ShaderID, name), 1, GL_FALSE, matrix.elements);
		}
	}
}