#include <GameScene.hpp>
#include <Scenes.hpp>
#include <GameLogic.h>
#include <Util.hpp>

using namespace uth;


namespace
{
    enum Layers
    {
        Default,
        Other
    };
}

void randomTypes(int array[])
{
	std::vector<int> types;
	types.push_back(3);
	types.push_back(2);
	types.push_back(1);
	types.push_back(1);
	types.push_back(1);

	int count = 0;
	for (int i = 0; i < types.size(); i++)
		count += types[i];

	for (int i = 0; i < 8; i++)
	{
		int random = rand()%count;
		int chosen = 0;
		while (random > 0)
		{
			random -= types[chosen];
			chosen++;
		}

		array[i] = chosen;
	}
}

GameScene::GameScene()
	: m_logic(m_info)
{}
GameScene::~GameScene()
{}

bool GameScene::Init()
{
	{
		GameObject* go;
		AddChild(go = new GameObject());
		go->AddComponent(new Sprite(pmath::Vec4(0,1,0,1),pmath::Vec2(1100,500)/*"test.tga"*/));
	}
	{
		AddChild(m_santa = new GameObject());
		m_santa->AddComponent(new Sprite("test.tga"));
	}

	int array[8];
	randomTypes(array);
	m_logic.SetTypes(array);

	const float width = 1400;
	const float height = 800;
	for (int i = 1; i <= 6; i++)
		m_waypoints.push_back({ -width / 2 + width / 6 * i, -height / 2 });
	for (int i = 1; i <= 2; i++)
		m_waypoints.push_back({ width / 2, -height / 2 + height/2 * i});
	for (int i = 5; i >= 0; i--)
		m_waypoints.push_back({ -width / 2 + width / 6 * i, height / 2 });
	for (int i = 1; i >= 0; i--)
		m_waypoints.push_back({ -width / 2, -height / 2 + height / 2 * i });

	return true;
}
bool GameScene::DeInit()
{
	return true;
}

void GameScene::Update(float dt)
{
	if (dt > 0.1)
		dt = 0.1;

	if (uthInput.Common == InputEvent::RELEASE)
	{
		pmath::Vec2 mousePos = uthEngine.GetWindow().PixelToCoords(uthInput.Common.Position());
		int index = 0;
		float distance = 90000000;
		for (int i = 0; i < 16; i += 2)
		{
			float dist = (m_waypoints[i] - mousePos).lengthSquared();
			if (dist < distance)
			{
				index = i/2;
				distance = dist;
			}
		}
		m_logic.MoveToIndex(index);
	}

	int index = m_info.position;
	float volume = m_info.position - index;
	index *= 2;
	m_santa->transform.SetPosition(Beziel(
		m_waypoints[index],
		m_waypoints[index+1],
		m_waypoints[(index+2)%16],
		volume
		));

	int reduced = m_logic.Update(dt);
	Scene::Update(dt);
}

//void TestScene::Draw(RenderTarget& target, RenderAttributes attributes)
//{
//	Scene::Draw(target, attributes);
//}
