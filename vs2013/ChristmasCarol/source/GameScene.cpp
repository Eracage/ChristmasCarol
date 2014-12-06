#include <GameScene.hpp>
#include <Scenes.hpp>
#include <GameLogic.h>

using namespace uth;


namespace
{
    enum Layers
    {
        Default,
        Other
    };
}

GameScene::GameScene()
	: m_logic(m_info)
{}
GameScene::~GameScene()
{}

bool GameScene::Init()
{
	int array[8];
	m_logic.SetTypes(array);
	return true;
}
bool GameScene::DeInit()
{
	return true;
}

void GameScene::Update(float dt)
{
	int reduced = m_logic.Update(dt);
	Scene::Update(dt);
}

//void TestScene::Draw(RenderTarget& target, RenderAttributes attributes)
//{
//	Scene::Draw(target, attributes);
//}
