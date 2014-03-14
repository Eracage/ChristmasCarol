#include "UtH/Engine/DefaultScene.hpp"
#include <UtH/Engine/Sprite.hpp>
#include <UtH/Platform/Input.hpp>
#include <UtH/Platform/Debug.hpp>

using namespace uth;

DefaultScene::DefaultScene()
{}
DefaultScene::~DefaultScene()
{}

bool DefaultScene::Init()
{
	shader.LoadShader("vertexshader.vert", "fragmentshader.frag");
	shader.Use();

	//camera.SetViewport(umath::rectangle(0, 0, 1600, 900));
	camera.SetSize(1600, 900);
	camera.SetPosition(0, 0);
	//camera.SetZoom(0);
	//camera.SetRotation(180);

	gameObject.AddComponent(new uth::Sprite("test.tga"));
	//gameObject.transform.SetSize(0.5f, 0.5f);
	//gameObject.transform.SetPosition(-0.5f, -0.5f);
	//gameObject.transform.parent->transform.Rotate(0);
	//gameObject.transform.SetSize(100, 100);

	return true;
}
bool DefaultScene::DeInit()
{
	return true;
}

bool DefaultScene::Update(double dt)
{
	umath::vector2 temp = uthInput.Touch.GetLastPos();

	if(temp.x != 0.0f || temp.y != 0.0f)
	{
		WriteLog("Touched %f %f",temp.x, temp.y);
	}

	return true;
}
bool DefaultScene::Draw()
{
	shader.SetUniform("unifProjection", camera.GetProjectionTransform());
	gameObject.Draw(&shader);
	return true;
}
