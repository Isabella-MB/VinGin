#include "window.h"

namespace vingin 
{
	namespace graphics
	{
		void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
		void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
		void cursor_position_callback(GLFWwindow *window, double x, double y);
		void window_resize(GLFWwindow *window, int width, int height);

		Window::Window(const char* title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			
			input = new Input();

			if (!init())
			{
				glfwTerminate();
			}
		}

		Window::~Window()
		{
			glfwTerminate();
			delete input;
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to initiailze GLFW" << std::endl;
				return false;
			}

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window)
			{
				std::cout << "Failed to create window!" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window, window_resize);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);

			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				std::cout << "Failed to initialize GLAD" << std::endl;
				return false;
			}

			std::cout << glGetString(GL_VERSION) << std::endl;


			return true;
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			glfwPollEvents();
			if (Window::input->mouseButtonPressed(GLFW_MOUSE_BUTTON_RIGHT))
				glfwSetWindowShouldClose(m_Window, 1);
			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window);
		}

		void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->input->keyCallback(window, key, scancode, action, mods);
		}

		void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->input->mouseButtonCallback(window, button, action, mods);
		}

		void cursor_position_callback(GLFWwindow *window, double x, double y)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->input->setCursorPositionCallback(window, x, y);
		}

		void window_resize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}
	}
}