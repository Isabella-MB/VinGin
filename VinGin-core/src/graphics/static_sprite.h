#pragma once

#include "renderable2d.h"

namespace vingin
{
	namespace graphics
	{
		class StaticSprite : public Renderable2D
		{
		public:
			StaticSprite(float x, float y, float width, float height, const math::vec4& color, Shader& shader);
			~StaticSprite();

			inline const Shader& getShader() const { return m_Shader; }

			inline const VertexArray* getVAO() const { return m_VertexArray; }
			inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }
		private:
			Shader & m_Shader;

			VertexArray *m_VertexArray;
			IndexBuffer *m_IndexBuffer;
		};
	}
}