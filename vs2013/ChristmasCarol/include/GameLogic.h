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

	void CalculateMoveDir();
	void Eat();

	CommonInfo& m_commonInfo;
	int m_targetIndex;
	int m_moveDir;
	bool m_eat;
};

#endif
