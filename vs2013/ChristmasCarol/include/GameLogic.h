#pragma once
#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <CommonInfo.h>
#include <UtH/UtHEngine.hpp>

class GameLogic
{
public:
	GameLogic(CommonInfo& commonInfo);
	~GameLogic();

	void SetTypes(int types[8]);

	void MoveToIndex(const int index);
	void EatInIndex(const int index);

	int Update(float dt);

private:
	struct Food
	{
		int type;
		int amount;
		int max;
	};

	void CalculateMoveDir();

	void Score(int amount);

	int Eat();

	void Burb();

	CommonInfo& m_commonInfo;
	int m_targetIndex;
	int m_lastIndex;
	int m_lastCount;

	int m_moveDir;
	bool m_eat;
	Food m_foods[8];

	int clicks;

	uth::Sound* sound;
};

#endif
