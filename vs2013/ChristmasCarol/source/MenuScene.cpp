#include <MenuScene.hpp>
#include <Scenes.hpp>
#include <Button.hpp>
#include <CommonInfo.h>

using namespace uth;

MenuScene::MenuScene()
{}
MenuScene::~MenuScene()
{}

bool MenuScene::Init()
{
	static bool firstInit = true;
	if (firstInit)
	{
		CommonInfo::music = uthRS.LoadSound("YYA - GTS JoululauluJope.wav");
		CommonInfo::music->SetVolume(50);
		CommonInfo::music->Play();
		CommonInfo::music->Loop(true);
		firstInit = false;
	}
	else
		CommonInfo::music->Play();

	uthEngine.GetWindow().GetCamera().SetSize(1920, 1080);
	time = 0;
	AddChild<GameObject>()->AddComponent(new Sprite("titleScreen.png"));

	/*const pmath::Vec2 startPos = pmath::Vec2(400,-400);
	const pmath::Vec2 endPos = pmath::Vec2(600  ,400);

	const int count = 3;
	for (int i = 0; i < count; i++)
	{
		GameObject* go;
		AddChild(go = new GameObject());
		go->transform.SetPosition(startPos + (endPos - startPos) * (i / (float)count));
		switch (i)
		{
		case 0:
			go->AddComponent(new Sprite("test.tga"));
			go->AddComponent(new Button([](){uthSceneM.GoToScene(SceneName::GAME); }));
			break;
		default:
			go->AddComponent(new Button([](){uthSceneM.GoToScene(-1); }));
			break;
		}
	}
*/

	return true;
}
bool MenuScene::DeInit()
{
	return true;
}

void MenuScene::Update(float dt)
{
	time += dt;
	if (time > 0.8)
		((GameObject*)Children()[0].get())->AddComponent(new Button([](){uthSceneM.GoToScene(SceneName::GAME); }));
	Scene::Update(dt);
}

//void TestScene::Draw(RenderTarget& target, RenderAttributes attributes)
//{
//	Scene::Draw(target, attributes);
//}
