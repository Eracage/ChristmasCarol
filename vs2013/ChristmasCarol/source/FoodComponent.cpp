#include <FoodComponent.h>
#include <UpdatingText.h>

using namespace uth;

FoodComponent::FoodComponent(int type)
	: Component("FoodComponent"),
	m_type(type)
{
}

FoodComponent::~FoodComponent()
{
}

void FoodComponent::Init()
{
	SpriteBatch* batch = static_cast<SpriteBatch*>(parent);
	
	//TODO:remove
	GameObject* go;
	parent->AddChild(go = new GameObject());
	go->AddComponent(new Sprite(pmath::Vec4(0.6, 0.2, 0.2, 1.0), pmath::Vec2(128, 128)));
	go->AddComponent(new UpdatingText<int>("", m_state));

	switch (m_type)
	{
		case 0:
		m_state = 5;

		//for (int i = 0; i < m_state + 1; i++)
		//{
		//	GameObject* go;
		//	parent->AddChild(go = new GameObject());
		//	if (i == 0)
		//	{
		//		go->AddComponent(new Sprite(pmath::Vec4(0.6, 0.2, 0.2, 1.0), pmath::Vec2(128, 128)));
		//		go->AddComponent(new UpdatingText<int>("", m_state));
		//	}
		//	else
		//		m_linkedObjects.push_back(go);

		//	go->transform.SetScale(0.2);
		//	go->transform.SetPosition(Randomizer::InsideCircle(100));
		//	go->transform.Rotate(Randomizer::GetInt(0, 360));
		//	go->AddComponent(new Sprite("test.tga"));
		//}
		break;
	case 1:
		m_state = 3;
		break;
	case 2:
		m_state = 3;
		break;
	case 3:
		m_state = 3;
		break;
	case 4:
		m_state = 1;
		break;
	}
}

void FoodComponent::DropState()
{
	m_state--;
}
