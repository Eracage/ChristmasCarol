#include <GameOverScene.hpp>
#include <Scenes.hpp>

using namespace uth;

GameOverScene::GameOverScene()
{}
GameOverScene::~GameOverScene()
{}

bool GameOverScene::Init()
{
	return true;
}
bool GameOverScene::DeInit()
{
	return true;
}

void GameOverScene::Update(float dt)
{
	Scene::Update(dt);
}

//void TestScene::Draw(RenderTarget& target, RenderAttributes attributes)
//{
//	Scene::Draw(target, attributes);
//}
