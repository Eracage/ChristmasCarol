#include <UtH/uthEngine.hpp>

#define NEWSCENEFUNC
#include <Scenes.hpp>
#include <HighScore.hpp>

int main()
{
	uthSceneM.registerNewSceneFunc(NewSceneFunc,SceneName::COUNT);

	srand(time(NULL));
	Highscore a;
	uthEngine.Init();

	while(uthEngine.Running())
	{
		uthEngine.Update();

		uthEngine.Draw();
	}

	return 0;
	//Hood.MainLoop(/*new StartScene*/);
	//uthSceneM.GoToScene(/*new GameScene*/1);
}