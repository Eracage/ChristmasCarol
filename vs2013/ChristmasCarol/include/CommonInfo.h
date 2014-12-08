#pragma once
#ifndef COMMONINFO_H
#define COMMONINFO_H
#include <UtH/UtHEngine.hpp>

struct CommonInfo
{
	static float time;
	static float boostTime;
	static float position;
	static unsigned long long score;
	static int multiplier;
	static float dangerTime;
	static float dangerPos;
	static uth::Sound* music;
};

#endif
