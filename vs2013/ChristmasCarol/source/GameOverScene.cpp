#include <GameOverScene.hpp>
#include <Scenes.hpp>
#include <Button.hpp>

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
	return true;
}
bool GameOverScene::DeInit()
{
	return true;
}

void GameOverScene::Update(float dt)
{
	time += dt;
	if (time > 0.8)
		((GameObject*)Children()[0].get())->AddComponent(new Button([](){uthSceneM.GoToScene(SceneName::MENU); }));
	Scene::Update(dt);
}

//void TestScene::Draw(RenderTarget& target, RenderAttributes attributes)
//{
//	Scene::Draw(target, attributes);
//}
