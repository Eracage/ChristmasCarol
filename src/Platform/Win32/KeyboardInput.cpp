#include <UtH/Platform/Win32/KeyboardInput.hpp>
#include <GLFW/glfw3.h>

enum Key
{
	BackSpace		  = GLFW_KEY_BACKSPACE,
	Tab				  = GLFW_KEY_TAB,
	Return			  = GLFW_KEY_ENTER,
	LeftControl		  = GLFW_KEY_LEFT_CONTROL,
	LeftAlt			  = GLFW_KEY_LEFT_ALT,
	Pause			  = GLFW_KEY_PAUSE,
	CapsLock		  = GLFW_KEY_CAPS_LOCK,
	Escape			  = GLFW_KEY_ESCAPE,
	Space			  = GLFW_KEY_SPACE,
	PageUp			  = GLFW_KEY_PAGE_UP,
	PageDown		  = GLFW_KEY_PAGE_DOWN,
	End				  = GLFW_KEY_END,
	Home			  = GLFW_KEY_HOME,
	Left			  = GLFW_KEY_LEFT,
	Up				  = GLFW_KEY_UP,
	Right			  = GLFW_KEY_RIGHT,
	Down			  = GLFW_KEY_DOWN,
	PrintScreen		  = GLFW_KEY_PRINT_SCREEN,
	Insert			  = GLFW_KEY_INSERT,
	Delete			  = GLFW_KEY_DELETE,
	Key0			  = GLFW_KEY_0,
	Key1			  = GLFW_KEY_1,
	Key2			  = GLFW_KEY_2,
	Key3			  = GLFW_KEY_3,
	Key4			  = GLFW_KEY_4,
	Key5			  = GLFW_KEY_5,
	Key6			  = GLFW_KEY_6,
	Key7			  = GLFW_KEY_7,
	Key8			  = GLFW_KEY_8,
	Key9			  = GLFW_KEY_9,
	A				  = GLFW_KEY_A,
	B				  = GLFW_KEY_B,
	C				  = GLFW_KEY_C,
	D				  = GLFW_KEY_D,
	E				  = GLFW_KEY_E,
	F				  = GLFW_KEY_F,
	G				  = GLFW_KEY_G,
	H				  = GLFW_KEY_H,
	I				  = GLFW_KEY_I,
	J				  = GLFW_KEY_J,
	K				  = GLFW_KEY_K,
	L				  = GLFW_KEY_L,
	M				  = GLFW_KEY_M,
	N				  = GLFW_KEY_N,
	O				  = GLFW_KEY_O,
	P				  = GLFW_KEY_P,
	Q				  = GLFW_KEY_Q,
	R				  = GLFW_KEY_R,
	S				  = GLFW_KEY_S,
	T				  = GLFW_KEY_T,
	U				  = GLFW_KEY_U,
	V				  = GLFW_KEY_V,
	W				  = GLFW_KEY_W,
	X				  = GLFW_KEY_X,
	Y				  = GLFW_KEY_Y,
	Z				  = GLFW_KEY_Z,
	Menu			  = GLFW_KEY_MENU,
	Numpad0			  = GLFW_KEY_KP_0,
	Numpad1			  = GLFW_KEY_KP_1,
	Numpad2			  = GLFW_KEY_KP_2,
	Numpad3			  = GLFW_KEY_KP_3,
	Numpad4			  = GLFW_KEY_KP_4,
	Numpad5			  = GLFW_KEY_KP_5,
	Numpad6			  = GLFW_KEY_KP_6,
	Numpad7			  = GLFW_KEY_KP_7,
	Numpad8			  = GLFW_KEY_KP_8,
	Numpad9			  = GLFW_KEY_KP_9,
	NumpadMultiply	  = GLFW_KEY_KP_MULTIPLY,
	NumpadAdd		  = GLFW_KEY_KP_ADD,
	NumpadSubtract	  = GLFW_KEY_KP_SUBTRACT,
	NumpadDecimal	  = GLFW_KEY_KP_DECIMAL,
	NumpadDivide	  = GLFW_KEY_KP_DIVIDE,
	F1				  = GLFW_KEY_F1,
	F2				  = GLFW_KEY_F2,
	F3				  = GLFW_KEY_F3,
	F4				  = GLFW_KEY_F4,
	F5				  = GLFW_KEY_F5,
	F6				  = GLFW_KEY_F6,
	F7				  = GLFW_KEY_F7,
	F8				  = GLFW_KEY_F8,
	F9				  = GLFW_KEY_F9,
	F10				  = GLFW_KEY_F10,
	F11				  = GLFW_KEY_F11,
	F12				  = GLFW_KEY_F12,
	NumLock			  = GLFW_KEY_NUM_LOCK,
	ScrollLock		  = GLFW_KEY_SCROLL_LOCK,
	LeftShift		  = GLFW_KEY_LEFT_SHIFT,
	RightShift		  = GLFW_KEY_RIGHT_SHIFT,
	RightControl	  = GLFW_KEY_RIGHT_CONTROL,
	RightAlt		  = GLFW_KEY_RIGHT_ALT,
	//LocalSemicolon	  = 0xBA, // �
	//LocalPlus		  = 0xBB,
	LocalComma		  = GLFW_KEY_COMMA,
	//LocalMinus		  = 0xBD,
	//LocalPeriod		  = 0xBE,
	//LocalSlash		  = 0xBF, // '
	//LocalTilde		  = 0xC0, // �
	LocalOpenBracket  = GLFW_KEY_LEFT_BRACKET, // �
	//LocalBackslash	  = 0xDC, // �
	LocalCloseBracket = GLFW_KEY_RIGHT_BRACKET, // �
	LocalQuote		  = GLFW_KEY_APOSTROPHE, // �
	//LocalAngleBracket = 0xE2,
	NumpadEnter		  = GLFW_KEY_KP_ENTER,
	COUNT			  = GLFW_KEY_LAST
};