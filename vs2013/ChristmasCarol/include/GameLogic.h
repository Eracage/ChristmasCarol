#pragma once
#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <CommonInfo.h>

class GameLogic
{
public:
	GameLogic(CommonInfo& commonInfo, int types[10]);
	~GameLogic();

	void MoveToIndex(const int index);
	void EatInIndex(const int index);

	int Update(float dt);

private:

};

#endif
