#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../input/input.h"

using namespace vingin::input;

namespace vingin 
{
	namespace graphics 
	{

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

		class Window
		{
		public:
			Window(const char *name, int width, int height);
			~Window();

			void clear() const;
			void update();
			bool closed() const;

			inline int getWidth() const { return m_Width; }
			inline int getHeight() const { return m_Height; }

			inline void getMousePosition(double &x, double &y) const
			{ 
				x = input->getMouseX(); 
				y = input->getMouseY();
			}

			friend static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow *window, double x, double y);
			friend static void window_resize(GLFWwindow *window, int width, int height);
		private:
			bool init();

			const char *m_Title;
			int m_Width, m_Height;

			GLFWwindow *m_Window;

			Input* input;
		};
	}
}
