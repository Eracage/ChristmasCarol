#include <CreditsScene.hpp>
#include <Scenes.hpp>
#include <Button.hpp>
#include <CommonInfo.h>
#include <UpdatingText.h>

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

	GameObject* go;
	AddChild(go = new GameObject());
	go->transform.SetPosition(-920, -540);
	go->AddComponent(new UpdatingText<unsigned long long>("Score: ", CommonInfo::score));
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
	if (time > 2)
		((GameObject*)Children()[0].get())->AddComponent(new Button([](){uthSceneM.GoToScene(SceneName::MENU); }));
	Scene::Update(dt);
}

//void TestScene::Draw(RenderTarget& target, RenderAttributes attributes)
//{
//	Scene::Draw(target, attributes);
//}
