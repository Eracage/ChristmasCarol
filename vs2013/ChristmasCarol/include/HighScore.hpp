#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <UtH/UtHEngine.hpp>

class Highscore : public uth::GameObject
{
	struct Score
	{
		char name[3];
		unsigned long long score;

	};
public:
	Highscore();
	~Highscore();

private:

	Score m_scores[10];
};

#endif
