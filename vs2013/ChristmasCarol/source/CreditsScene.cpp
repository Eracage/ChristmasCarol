#include <CreditsScene.hpp>
#include <Scenes.hpp>

using namespace uth;


namespace
{
    enum Layers
    {
        Default,
        Other
    };
}

CreditsScene::CreditsScene()
{}
CreditsScene::~CreditsScene()
{}

bool CreditsScene::Init()
{
	return true;
}
bool CreditsScene::DeInit()
{
	return true;
}

void CreditsScene::Update(float dt)
{
	Scene::Update(dt);
}

//void TestScene::Draw(RenderTarget& target, RenderAttributes attributes)
//{
//	Scene::Draw(target, attributes);
//}
