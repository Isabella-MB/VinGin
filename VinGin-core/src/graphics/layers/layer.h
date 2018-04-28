#pragma once

#include <vector>
#include "../renderer2d.h"
#include "../renderable2d.h"

namespace vingin
{
	namespace graphics
	{
		class Layer
		{
		public:
			virtual ~Layer();
			virtual void add(Renderable2D *renderable);
			virtual void render();
		protected:
			Layer(Renderer2D *renderer, math::mat4 projection, Shader *shader);

			Renderer2D *m_Renderer;
			std::vector<Renderable2D*> m_Renderables;
			Shader *m_Shader;
			math::mat4 m_Projection;
		};
	}
}