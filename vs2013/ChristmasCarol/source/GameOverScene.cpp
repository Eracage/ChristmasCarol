#include <GameOverScene.hpp>
#include <Scenes.hpp>
#include <Button.hpp>
#include <CommonInfo.h>
#include <UpdatingText.h>

using namespace uth;

GameOverScene::GameOverScene()
{}
GameOverScene::~GameOverScene()
{}

bool GameOverScene::Init()
{
	Sound* sound = uthRS.LoadSound("rrooyyh.wav");
	sound->SetPitch(80);
	sound->Play();
	time = 0;
	AddChild<GameObject>()->AddComponent(new Sprite("ending1.png"));

	GameObject* go;
	AddChild(go = new GameObject());
	go->transform.SetPosition(-920, -540);
	go->AddComponent(new UpdatingText<unsigned long long>("Score: ", CommonInfo::score));
	return true;
}
bool GameOverScene::DeInit()
{
	return true;
}

void GameOverScene::Update(float dt)
{
	time += dt;
	if (time > 2)
		((GameObject*)Children()[0].get())->AddComponent(new Button([](){uthSceneM.GoToScene(SceneName::MENU); }));
	Scene::Update(dt);
}

//void TestScene::Draw(RenderTarget& target, RenderAttributes attributes)
//{
//	Scene::Draw(target, attributes);
//}
