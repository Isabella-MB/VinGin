#pragma once

#include <glad/glad.h>

namespace vingin
{
	namespace graphics
	{
		class IndexBuffer
		{
		public:
			IndexBuffer(GLushort *data, GLsizei count);
			~IndexBuffer();

			void bind() const;
			void unbind() const;

			inline GLuint getCount() const { return m_Count; }
		private:
			GLuint m_BufferID;
			GLuint m_Count;
		};
	}
}