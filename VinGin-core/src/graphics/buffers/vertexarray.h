#pragma once

#include <vector>
#include <glad\glad.h>

#include "buffer.h"

namespace vingin
{
	namespace graphics
	{
		class VertexArray 
		{
		public:
			VertexArray();
			~VertexArray();

			void addBuffer(Buffer *buffer, GLuint index);
			void bind() const;
			void unbind() const;
		private:
			GLuint m_ArrayID;
			std::vector<Buffer*> m_Buffers;
		};
	}
}