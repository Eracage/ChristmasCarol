#include <GameScene.hpp>
#include <Scenes.hpp>
#include <GameLogic.h>
#include <Util.hpp>
#include <Button.hpp>
#include <UpdatingText.h>
#include <FoodComponent.h>
#include <Danger.h>

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
	for (int i = 0; i < 3; i++) types.push_back(0);
	for (int i = 0; i < 2; i++) types.push_back(1);
	for (int i = 0; i < 1; i++) types.push_back(2);
	for (int i = 0; i < 1; i++) types.push_back(3);
	for (int i = 0; i < 1; i++) types.push_back(4);

	random_shuffle(types.begin(), types.end());
	for (int i = 0; i < 8; ++i)
		array[i] = types[i];
}

GameScene::GameScene()
	: m_logic(m_info)
{}
GameScene::~GameScene()
{}

bool GameScene::Init()
{
	m_atlas.LoadFromFile("sprites.xml");

	const float tableScale = 0.6f;

	const float width = 1660 * tableScale;
	const float height = 1240 * tableScale;
	for (int i = 1; i <= 6; i++)
		m_waypoints.push_back({ -width / 2 + width / 6 * i, -height / 2 });
	for (int i = 1; i <= 2; i++)
		m_waypoints.push_back({ width / 2, -height / 2 + height / 2 * i });
	for (int i = 5; i >= 0; i--)
		m_waypoints.push_back({ -width / 2 + width / 6 * i, height / 2 });
	for (int i = 1; i >= 0; i--)
		m_waypoints.push_back({ -width / 2, -height / 2 + height / 2 * i });

	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 3; y++)
		{
			GameObject* go;
			AddChild(go = new GameObject());
			Sprite* s;
			go->AddComponent(s = new Sprite("floor.png"));
			go->transform.SetPosition(-1024 + 512 * x, -768 + 512 * y);
			go->transform.SetOrigin(7);
			s->SetColor(pmath::Vec4(0.8, 0.8, 0.8, 1));
		}

#pragma region Texts
	{
		GameObject* go;
		AddChild(go = new GameObject());
		go->transform.SetPosition(-920, -540);
		go->AddComponent(new UpdatingText<unsigned long long>("Score: ", m_info.score));
	}
	{
		GameObject* go;
		AddChild(go = new GameObject());
		go->transform.SetPosition(-920, -500);
		go->AddComponent(new UpdatingText<int>("Multiplier: ", m_info.multiplier, " X"));
	}
	{
		GameObject* go;
		AddChild(go = new GameObject());
		go->transform.SetPosition(-920, -460);
		go->AddComponent(new UpdatingText<float, int>("Time: ", m_info.time, "s"));
	}
	{
		GameObject* go;
		AddChild(go = new GameObject());
		go->transform.SetPosition(-920, -420);
		go->AddComponent(new UpdatingText<float, int>("Boost: ", m_info.boostTime, "s"));
	}
#pragma endregion

	{
		AddChild(m_batch = new SpriteBatch(false));
		m_batch->SetTextureAtlas(&m_atlas);

		for (int i = 0; i < 8; i++)
		{
			Transform* transform = new Transform(nullptr);
			m_batch->AddSprite(transform,"chair.png");

			transform->SetPosition(
				m_waypoints[i * 2].x,
				m_waypoints[i * 2].y);
			if ((i + 1) % 4 == 0)
			{
				transform->SetPosition(
					m_waypoints[i * 2].x - (m_waypoints[i * 2].x > 0 ? 1 : -1) * 30,
					m_waypoints[i * 2].y);
				transform->SetRotation((m_waypoints[i * 2].x > 0 ? 1 : -1) * 90);
			}
			else
			{
				transform->SetPosition(
					m_waypoints[i * 2].x * 0.9,
					m_waypoints[i * 2].y - (m_waypoints[i * 2].y > 0 ? 1 : -1) * 30);
				transform->SetRotation((m_waypoints[i * 2].y > 0 ? 1 : -1) * 90 + 90);
			}
			transform->SetScale(0.6f);
		}
	}

	{
		GameObject* go;
		AddChild(go = new GameObject());
		go->AddComponent(new Sprite("table.png"/*pmath::Vec4(0,1,0,1),pmath::Vec2(1100,500)*/));
		go->transform.SetScale(tableScale);
	}
	{
		AddChild(m_batch = new SpriteBatch(false));
		m_batch->SetTextureAtlas(&m_atlas);
	}
	{
		AddChild(m_santa = new GameObject());
		m_santa->AddComponent(new AnimatedSprite(uthRS.LoadTexture("santa.png"),4,4,2));
		m_santa->transform.SetScale(0.6);
	}

	

	int array[8];
	randomTypes(array);
	m_logic.SetTypes(array);
	for (int i = 0; i < 8; i++)
	{
		static GameLogic* logic = &m_logic;
		logic = &m_logic;
		GameObject* go;
		Button* btn;
		m_batch->AddChild(go = new GameObject("Food"));
		go->AddComponent(new FoodComponent(array[i]));
		go->AddComponent(btn = new Button([i](){logic->EatInIndex(i); }));
		btn->SetSize({ 128, 128 });

		if ((i + 1) % 4 == 0)
		{
			go->transform.SetPosition(
				m_waypoints[i * 2].x - (m_waypoints[i * 2].x > 0 ? 1 : -1) * 170,
				m_waypoints[i * 2].y);
		}
		else
		{
			go->transform.SetPosition(
				m_waypoints[i * 2].x * 0.9,
				m_waypoints[i * 2].y - (m_waypoints[i * 2].y > 0 ? 1 : -1) * 160);
		}
	}
	{
		Danger* d;
		AddChild(d = new Danger());
		d->Init();
	}
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

	float angle = m_santa->transform.GetPosition().angle() + 90;
	m_santa->transform.SetRotation(angle);

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
	if (reduced != -1)
		((GameObject*)m_batch->Children("Food")[reduced].get())->GetComponent<FoodComponent>()->DropState();
	Scene::Update(dt);
}

//void TestScene::Draw(RenderTarget& target, RenderAttributes attributes)
//{
//	Scene::Draw(target, attributes);
//}
