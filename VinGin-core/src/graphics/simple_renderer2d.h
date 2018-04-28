#pragma once

#include <deque>
#include "renderer2d.h"
#include "renderable2d.h"

namespace vingin
{
	namespace graphics
	{
		class SimpleRenderer2D : public Renderer2D
		{
		public:
			void submit(const Renderable2D *renderable) override;
			void flush() override;
		private:
			std::deque<const Renderable2D*> m_RenderQueue;
		};
	}
}