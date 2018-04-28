#include "renderable2d.h"

namespace vingin
{
	namespace graphics
	{
		Renderable2D::Renderable2D(math::vec3 position, math::vec2 size, math::vec4 color)
			: m_Position(position), m_Size(size), m_Color(color)
		{
		}

		Renderable2D::~Renderable2D()
		{
		}
	}
}