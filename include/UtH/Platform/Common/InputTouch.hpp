#pragma once
#ifndef INPUTTOUCH_H_UTH
#define INPUTTOUCH_H_UTH

#include <UtH/Platform/Common/InputBase.hpp>

namespace uth
{
	class TouchInput : public InputBase
	{
	public:
		TouchInput(){}
		~TouchInput(){}
		void Update(float dt){}
//		Touch tlist[8]
	};
}

#endif