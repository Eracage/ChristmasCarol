#include <GameLogic.h>

GameLogic::GameLogic(CommonInfo& commonInfo)
	: m_commonInfo(commonInfo),
	m_targetIndex(1),
	m_lastIndex(-1),
	m_lastCount(0),
	m_moveDir(0),
	m_eat(false)
{
	m_commonInfo.time = 60;
	m_commonInfo.boostTime = 0;
	m_commonInfo.position = 1;
	m_commonInfo.score = 0;
	m_commonInfo.multiplier = 1;
}

GameLogic::~GameLogic()
{

}

void GameLogic::SetTypes(int types[8])
{
	for (int i = 0; i < 8; i++)
	{
		m_foods[i].type = types[i];
		switch (types[i])
		{
		case 0:
			m_foods[i].amount = 10;
			break;
		case 1:
			m_foods[i].amount = 15;
			break;
		case 2:
			m_foods[i].amount = 25;
			break;
		case 3:
			m_foods[i].amount = 30;
			break;
		case 4:
			m_foods[i].amount = 1;
			break;
		}
		m_foods[i].max = m_foods[i].amount;
	}
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
	CalculateMoveDir();
	m_eat = m_moveDir == 0;
}

int GameLogic::Update(float dt)
{
	m_commonInfo.time -= dt;
	if (m_commonInfo.time < 0)
		m_commonInfo.time = 0;
	m_commonInfo.boostTime -= dt;
	if (m_commonInfo.boostTime < 0)
		m_commonInfo.boostTime = 0;

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
	{
		m_eat = false;

		return Eat();
	}

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

void GameLogic::Score(int amount)
{
	m_commonInfo.score += amount * m_commonInfo.multiplier;
}

int GameLogic::Eat()
{
	int retVal = -1;

	const int eatAmount = m_commonInfo.boostTime > 0 ? 2 : 1;

	for (int m = 0; m < eatAmount; m++)
	{
		const int i = m_targetIndex;
		const int a = m_foods[i].amount;

		if (a == 0)
			return retVal;

		if (i == m_lastIndex)
		{
			m_lastCount++;
		}
		else if (m_lastCount != 0)
		{
			m_commonInfo.multiplier = 1;
			m_lastCount = 1;
		}
		else
		{
			m_lastCount = 1;
		}

		m_foods[i].amount--;

		m_lastIndex = m_targetIndex;

		switch (m_foods[i].type)
		{
		case 0:
			if (m_foods[i].amount > 0)
				Score(50);
			else
				Score(50 + 100);

			switch (m_foods[i].amount)
			{
			case 0:
			case 2:
			case 4:
			case 6:
			case 8:
				retVal = i;
				break;
			default:
				break;
			}
			break;
		case 1:
			if (m_foods[i].amount > 0)
				Score(75);
			else
				Score(75 + 100);

			switch (m_foods[i].amount)
			{
			case 0:
			case 5:
			case 10:
				retVal = i;
				break;
			default:
				break;
			}
			break;
		case 2:
			if (m_foods[i].amount > 0)
				Score(100);
			else
				Score(100 + 100);

			switch (m_foods[i].amount)
			{
			case 0:
			case 8:
			case 16:
				retVal = i;
				break;
			default:
				break;
			}
			break;
		case 3:
			if (m_foods[i].amount > 0)
				Score(150);
			else
				Score(150 + 100);

			switch (m_foods[i].amount)
			{
			case 0:
			case 10:
			case 20:
				retVal = i;
				break;
			default:
				break;
			}
			break;
		case 4:
				Score(500);
				m_commonInfo.boostTime = 15.0f;
				retVal = i;
			break;
		}

		if (m_lastCount == m_foods[i].max)
		{
			if (m_foods[i].type != 4)
				m_commonInfo.multiplier++;
			m_lastCount = 0;
		}

	}
	return retVal;
}
