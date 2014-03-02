#include <UtH/Platform/Win32/MouseInput.hpp>

namespace uth
{
	MouseInput::MouseInput()
		: m_buttons(Mouse::COUNT, false),
		  m_Lbuttons(m_buttons)
	{}
	MouseInput::~MouseInput()
	{}
	bool MouseInput::IsButtonDown(Mouse::MButton Button)
	{
		return m_buttons.at(Button);
	}
	bool MouseInput::IsButtonPressed(Mouse::MButton Button)
	{
		return m_buttons.at(Button) && !m_Lbuttons.at(Button);
	}
	bool MouseInput::IsButtonReleased(Mouse::MButton Button)
	{
		return !m_buttons.at(Button) && m_Lbuttons.at(Button);
	}
	umath::vector2 MouseInput::MousePosition()
	{
		return m_pos;
	}
	umath::vector2 MouseInput::MouseMovement()
	{
		return m_pos - m_Lpos;
	}
	//int MouseInput::MouseWheel()
	//{}
	void MouseInput::Update(void* windowHandle)
	{
		GLFWwindow *window = static_cast<GLFWwindow*>(windowHandle);
		m_Lpos = m_pos;
		double x,y;
		glfwGetCursorPos(window,&x,&y);
		m_pos.x = x;
		m_pos.y = y;

		for (int i = 0; i < Mouse::COUNT; i++)
		{
			if (m_buttons.at(i))
			{
				int j = 0;
				j++;
			}
			m_Lbuttons.at(i) = m_buttons.at(i);
			m_buttons.at(i) = (bool)glfwGetMouseButton(window, i);
		}
	}
}
//
//void scroll(GLFWwindow *window, double x, double y)
//{
//
//}
