#pragma once

#include <iostream>
#include <GLFW\glfw3.h>

namespace vingin 
{
	namespace input
	{

#define KEY_COUNT 1024
#define MOUSE_BUTTON_COUNT 32

		class Input
		{
		public:
			Input();
			~Input();

			void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
			void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
			void setCursorPositionCallback(GLFWwindow *window, double x, double y);

			bool keyPressed(int keycode) const;
			bool mouseButtonPressed(int button) const;
			double getMouseX() const;
			double getMouseY() const;

		private:
			bool m_Keys[KEY_COUNT];
			bool m_MouseButtons[MOUSE_BUTTON_COUNT];

			double m_MouseX, m_MouseY;
		};
	}
}
