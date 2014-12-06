#include "GameLogic.h"

GameLogic::GameLogic(CommonInfo& commonInfo)
	: m_commonInfo(commonInfo),
	m_targetIndex(1),
	m_moveDir(0),
	m_eat(false)
{
	m_commonInfo.position = 1;
	m_commonInfo.time = 60;
}

GameLogic::~GameLogic()
{

}

void GameLogic::SetTypes(int types[8])
{

}

void GameLogic::MoveToIndex(const int index)
{
	m_targetIndex = index;
	m_eat = false;
	CalculateMoveDir();
}

void GameLogic::EatInIndex(const int index)
{
	m_targetIndex;
	m_eat = true;
	CalculateMoveDir();
}

int GameLogic::Update(float dt)
{
	if (m_moveDir != 0)
	{
		m_commonInfo.position += dt * m_moveDir;
		if (m_commonInfo.position >= 8)
			m_commonInfo.position -= 8;
		if (m_commonInfo.position < 0)
			m_commonInfo.position += 8;

		float dif = m_targetIndex - m_commonInfo.position;



		if (m_moveDir == 1)
		{
			if (m_targetIndex == (int)m_commonInfo.position)
			{
				m_moveDir = 0;
				m_commonInfo.position = m_targetIndex;
			}
		}
		else if (m_moveDir == -1)
		{
			if ((m_targetIndex?m_targetIndex-1:7) == (int)m_commonInfo.position)
			{
				m_moveDir = 0;
				m_commonInfo.position = m_targetIndex;
			}
		}
	}
	else if (m_eat)
		Eat();

	return -1;
}

void GameLogic::CalculateMoveDir()
{
	float dif = m_targetIndex - m_commonInfo.position;

	if (dif < -4)
		dif += 8;
	else if (dif > 4)
		dif -= 8;

	if (dif < 0)
		m_moveDir = -1;
	else if (dif > 0)
		m_moveDir = 1;
	else
		m_moveDir = 0;
}

void GameLogic::Eat()
{

}
