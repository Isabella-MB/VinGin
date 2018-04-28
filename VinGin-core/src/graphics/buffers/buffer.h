#pragma once

#include <glad/glad.h>

namespace vingin
{
	namespace graphics
	{
		class Buffer 
		{
		public:
			Buffer(GLfloat *data, GLsizei count, GLuint componentCount);
			~Buffer();

			void bind() const;
			void unbind() const;

			inline GLuint getComponentCount() { return m_ComponentCount; }
		private:
			GLuint m_BufferID;
			GLuint m_ComponentCount;
		};
	}
}