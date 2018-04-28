#include "simple_renderer2d.h"

namespace vingin
{
	namespace graphics
	{
		void SimpleRenderer2D::submit(const Renderable2D *renderable)
		{
			m_RenderQueue.push_back(renderable);
		}

		void SimpleRenderer2D::flush()
		{
			while (!m_RenderQueue.empty())
			{
				const Renderable2D *renderable = m_RenderQueue.front();
				//renderable->getVAO()->bind();
				//renderable->getIBO()->bind();

				//renderable->getShader().setUniformMat4("model", math::mat4::translate(renderable->getPosition()));
				//glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_SHORT, 0);

				//renderable->getIBO()->unbind();
				//renderable->getVAO()->unbind();

				m_RenderQueue.pop_front();
			}
		}
	}
}