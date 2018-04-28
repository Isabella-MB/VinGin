#include "input.h"


namespace vingin
{
	namespace input
	{
		Input::Input()
		{
			for (int i = 0; i < KEY_COUNT; i++)
			{
				m_Keys[i] = false;
			}
			
			for (int i = 0; i < MOUSE_BUTTON_COUNT; i++)
			{
				m_MouseButtons[i] = false;
			}
		}

		Input::~Input()
		{
		}

		bool Input::keyPressed(int keycode) const
		{
			if (keycode >= KEY_COUNT)
			{
				std::cout << "Keycode out of range" << std::endl;
				return false;
			}
			return m_Keys[keycode];
		}

		bool Input::mouseButtonPressed(int button) const
		{
			if (button >= MOUSE_BUTTON_COUNT)
			{
				std::cout << "Mouse button out of range" << std::endl;
				return false;
			}
			return m_MouseButtons[button];
		}

		double Input::getMouseX() const
		{
			return m_MouseX;
		}

		double Input::getMouseY() const
		{
			return m_MouseY;
		}

		void Input::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
		{
			m_Keys[key] = action != GLFW_RELEASE;
		}

		void Input::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
		{
			m_MouseButtons[button] = action != GLFW_RELEASE;
		}

		void Input::setCursorPositionCallback(GLFWwindow *window, double x, double y)
		{
			m_MouseX = x;
			m_MouseY = y;
		}
	}
}