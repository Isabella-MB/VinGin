#include "layer.h"

namespace vingin
{
	namespace graphics
	{
		Layer::Layer(Renderer2D *renderer, math::mat4 projection, Shader *shader)
			:	m_Renderer(renderer), m_Projection(projection), m_Shader(shader)
		{
			m_Shader->enable();
			m_Shader->setUniformMat4("projection", m_Projection);
			m_Shader->disable();
		}

		Layer::~Layer()
		{
			delete m_Shader;
			delete m_Renderer;
			for (int i = 0; i < m_Renderables.size(); i++)
				delete m_Renderables[i];
		}

		void Layer::add(Renderable2D *renderable)
		{
			m_Renderables.push_back(renderable);
		}

		void Layer::render()
		{
			m_Shader->enable();

			for (const Renderable2D *renderable : m_Renderables)
				m_Renderer->submit(renderable);

			m_Renderer->flush();
			m_Shader->disable();
		}
	}
}