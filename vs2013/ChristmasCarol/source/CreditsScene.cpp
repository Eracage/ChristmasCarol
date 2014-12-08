#include <CreditsScene.hpp>
#include <Scenes.hpp>
#include <Button.hpp>
#include <CommonInfo.h>

using namespace uth;

CreditsScene::CreditsScene()
{}
CreditsScene::~CreditsScene()
{}

bool CreditsScene::Init()
{
	CommonInfo::music->Pause(true);
	uthRS.LoadSound("YYAJam - LadyScreaming.wav")->Play();
	
	time = 0;
	AddChild<GameObject>()->AddComponent(new Sprite("ending2.png"));
	return true;
}
bool CreditsScene::DeInit()
{
	CommonInfo::music->Pause(false);
	return true;
}

void CreditsScene::Update(float dt)
{
	time += dt;
	if (time > 0.2)
		((GameObject*)Children()[0].get())->AddComponent(new Button([](){uthSceneM.GoToScene(SceneName::MENU); }));
	Scene::Update(dt);
}

//void TestScene::Draw(RenderTarget& target, RenderAttributes attributes)
//{
//	Scene::Draw(target, attributes);
//}
