#pragma once
#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <CommonInfo.h>

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

	CommonInfo& m_commonInfo;
	int m_targetIndex;
	int m_lastIndex;
	int m_lastCount;

	int m_moveDir;
	bool m_eat;
	Food m_foods[8];

	float m_timer;
	float m_boostTimer;
};

#endif
