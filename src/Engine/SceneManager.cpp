#include <UtH/Platform/Debug.hpp>
#include <cassert>
#include <UtH/Engine/SceneManager.hpp>

#include <UtH/Engine/DefaultScene.hpp>
#include <UtH/Engine/Engine.hpp>

namespace uth
{
	Scene* defaultNewSceneFunc(int SceneID)
	{
		return nullptr;
	}

	SceneManager::SceneManager()
		: m_nextScene(UTHDefaultScene),
		  m_pendingSceneSwitch(true)
	{
		registerNewSceneFunc(defaultNewSceneFunc, 0);
	}
	SceneManager::~SceneManager()
	{
		curScene->DeInit();
		delete curScene;
	}
	
	void SceneManager::GoToScene(int SceneID, bool /*disposeCurrent*/)
	{
		// TODO:
        // disposeCurrent;
		if (!(UTHDefaultScene <= SceneID && SceneID < sceneCount))
		{
			WriteError("Error when scene %d switching to %d, number out of range, switching to default scene",m_sceneID, m_nextScene);
			m_sceneID = -1;
			return;
		}
		m_pendingSceneSwitch = true;
		m_nextScene = SceneID;
	}

	void SceneManager::Update(float dt)
	{
		if (m_pendingSceneSwitch)
			m_switchScene();

		curScene->Update(dt);
	}

	void SceneManager::Draw()
	{
		curScene->Draw(uthEngine.GetWindow());
	}
	
	void SceneManager::registerNewSceneFunc(Scene* (*newSceneFunc)(int SceneID), int SceneCount)
	{
		makeActiveScene = newSceneFunc;
		sceneCount = SceneCount;
	}

	// private

	void SceneManager::AndroidReturn()
	{
		if (curScene)
			curScene->AndroidReturn();
	}
	void SceneManager::AndroidLeave()
	{
		if (curScene)
			curScene->AndroidLeave();
	}

	void SceneManager::endScene()
	{
		if (!curScene->DeInit())
			WriteError("Scene %d DeInit() func returns false",m_sceneID);
		delete curScene;
	}
	void SceneManager::startScene()
	{
		if (curScene->Init())
			m_sceneID = m_nextScene;
		else
		{
			WriteError("Scene %d Init() func returns false",m_sceneID);
			m_nextScene = -1;
			m_switchScene();
		}
	}

	void SceneManager::m_switchScene()
	{
		if (curScene != nullptr)
			endScene();
		Scene* newScene = makeActiveScene(m_nextScene);
		if (newScene)
			curScene = newScene;
		else
			curScene = new uth::DefaultScene();
		startScene();
		m_pendingSceneSwitch = false;
	}

}