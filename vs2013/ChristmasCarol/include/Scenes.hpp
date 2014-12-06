#ifndef SCENES_H
#define SCENES_H
#define UTHDefaultScene -1

// Enumeration of scenes, giving name for each scene number
namespace SceneName
{
	enum
	{
		DEFAULT = UTHDefaultScene,
		MENU,
		GAME,
		GAMEOVER,
		CREDITS,
		COUNT // Keep this last, it tells how many scenes there are
	};
}

#endif //SCENES_H

#ifdef NEWSCENEFUNC
#undef NEWSCENEFUNC

#include <MenuScene.hpp>
#include <GameScene.hpp>
#include <GameOverScene.hpp>
#include <CreditsScene.hpp>

// Create function for a new scene, having a case for every user made scene
uth::Scene* NewSceneFunc(int SceneID)
{
	switch (SceneID)
	{
	case SceneName::MENU:		return new MenuScene();
	case SceneName::GAME:		return new GameScene();
	case SceneName::GAMEOVER:	//return new GameOverScene();
	case SceneName::CREDITS:	//return new CreditsScene();
	default:		return nullptr;
	}
}

#endif // NEWSCENEFUNC