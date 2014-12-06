#include "FoodComponent.h"

using namespace uth;

FoodComponent::FoodComponent(int type)
	: Component("FoodComponent")
{
	switch (type)
	{
	case 0:
		state = 5;
		for (int i = 0; i < state+1; i++)
		{
			GameObject* go;
			parent->AddChild(go = new GameObject());
			if (i == 0)
				go->AddComponent(new Sprite("test.tga"));
			else
				m_linkedObjects.push_back(go);

			go->transform.SetScale(0.2);
			go->transform.SetPosition(Randomizer::InsideCircle(100));
			go->transform.Rotate(Randomizer::GetInt(0, 360));
			go->AddComponent(new Sprite("test.tga"));
			break;
		}
		break;
	case 1:
		state = 3;
		break;
	case 2:
		state = 3;
		break;
	case 3:
		state = 3;
		break;
	case 4:
		state = 1;
		break;
	}
}

FoodComponent::~FoodComponent()
{
}

void FoodComponent::DropState()
{

}
