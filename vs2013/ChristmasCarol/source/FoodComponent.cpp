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
	SpriteBatch* batch = parent->Parent<SpriteBatch>();

	//TODO:remove
	//GameObject* go;
	//parent->AddChild(go = new GameObject());
	//go->AddComponent(new Sprite(pmath::Vec4(0.6, 0.2, 0.2, 1.0), pmath::Vec2(128, 128)));
	//go->AddComponent(new UpdatingText<int>("", m_state));


	float r = Randomizer::GetFloat();
	switch (m_type)
	{
	case 0:
		m_state = 5;

		for (int i = 0; i < m_state + 1; i++)
		{
			m_objects.push_back(new Object);
			parent->AddChild(m_objects.back());
			m_objects.back()->SetActive(false);

			switch (i)
			{
			case 0:
				batch->AddSprite(&m_objects.back()->transform, "plate2.png");
				m_objects.back()->transform.SetScale(Randomizer::GetFloat(0.4, 0.5)*1.5);
				break;
			default:
				m_objects.back()->transform.SetPosition(
					pmath::Mat2::createRotation(i * 72) *
					pmath::Vec2(Randomizer::GetFloat(20, 40), 0));
				m_objects.back()->transform.SetRotation(Randomizer::GetInt(0, 360));
				m_objects.back()->transform.SetScale(Randomizer::GetFloat(0.4, 0.5));

				if (r < 0.33)batch->AddSprite(&m_objects.back()->transform, "candy.png");
				else if (r < 0.66)batch->AddSprite(&m_objects.back()->transform, "cookies.png");
				else batch->AddSprite(&m_objects.back()->transform, "gingerbread.png");
				break;
			}
		}
		break;
	case 1:
		m_state = 3;

		for (int i = 0; i < m_state; i++)
		{
			m_objects.push_back(new Object);
			parent->AddChild(m_objects.back());
			m_objects.back()->SetActive(false);

			switch (i)
			{
			case 0:
				m_objects.back()->transform.SetScale(Randomizer::GetFloat(0.4, 0.45));
				m_objects.back()->transform.SetPosition(0, -30);
				break;
			case 1:
				m_objects.back()->transform.SetScale(Randomizer::GetFloat(0.45, 0.5));
				m_objects.back()->transform.SetPosition(30, 30);
				break;
			case 2:
				m_objects.back()->transform.SetScale(Randomizer::GetFloat(0.45, 0.5));
				m_objects.back()->transform.SetPosition(-30, 30);
				break;
			}
			m_objects.back()->transform.Move(Randomizer::InsideCircle(10));
			m_objects.back()->transform.SetOrigin({ 0, 20 });

			if (r < 0.5)
			{
				batch->AddSprite(&m_objects.back()->transform, "wineFull.png");
				m_type = 5;
			}
			else
				batch->AddSprite(&m_objects.back()->transform, "milkFull.png");
		}
		break;
	case 2:
		m_state = 6;
		{
			float r2 = Randomizer::GetFloat(0.4, 0.5);
			for (int i = 0; i < m_state + 1; i++)
			{
				m_objects.push_back(new Object);
				parent->AddChild(m_objects.back());
				m_objects.back()->SetActive(false);

				switch (i)
				{
				case 0:
					if (r < 0.5)batch->AddSprite(&m_objects.back()->transform, "plate2.png");
					else batch->AddSprite(&m_objects.back()->transform, "plate4.png");
					m_objects.back()->transform.SetScale(r2*1.5);
					break;
				case 6:
					if (r < 0.33)batch->AddSprite(&m_objects.back()->transform, "porridge.png");
					else if (r < 0.66)batch->AddSprite(&m_objects.back()->transform, "salad.png");
					else batch->AddSprite(&m_objects.back()->transform, "rosolli.png");
					m_objects.back()->transform.SetScale(r2);
					break;
				default:
					if (r < 0.33)batch->AddSprite(&m_objects.back()->transform, "porridge.png");
					else if (r < 0.66)batch->AddSprite(&m_objects.back()->transform, "salad.png");
					else batch->AddSprite(&m_objects.back()->transform, "rosolli.png");
					m_objects.back()->transform.SetPosition(
						pmath::Mat2::createRotation(72 * i) *
						pmath::Vec2(Randomizer::GetFloat(25,45), 0));
					m_objects.back()->transform.SetRotation(Randomizer::GetInt(-30, 30));
					m_objects.back()->transform.SetScale(r2);
					break;
				}
			}
		}
		break;
	case 3:
		m_state = 3;
		{
			float r2 = Randomizer::GetFloat(0.4, 0.5);
			for (int i = 0; i < m_state + 1; i++)
			{
				m_objects.push_back(new Object);
				parent->AddChild(m_objects.back());
				m_objects.back()->SetActive(false);

				r = 0.2;

				switch (i)
				{
				case 0:
					if (r < 0.33)batch->AddSprite(&m_objects.back()->transform, "plate1.png");
					else if (r < 0.66)batch->AddSprite(&m_objects.back()->transform, "plate2.png");
					else batch->AddSprite(&m_objects.back()->transform, "plate1.png");
					m_objects.back()->transform.SetScale(r2*1.5);
					break;
				case 1:
					if (r < 0.33)
					{
						batch->AddSprite(&m_objects.back()->transform, "turkey3.png");
					}
					else if (r < 0.66)
					{
						batch->AddSprite(&m_objects.back()->transform, "cake3.png");
						m_objects.back()->transform.SetPosition(2, 8);
					}
					else
					{
						batch->AddSprite(&m_objects.back()->transform, "ham3.png");
						m_objects.back()->transform.SetPosition(8, 0);
					}
					m_objects.back()->transform.SetScale(r2);
					break;
				case 2:
					if (r < 0.33)
					{
						batch->AddSprite(&m_objects.back()->transform, "turkey1.png");
						m_objects.back()->transform.SetPosition(-2, -10);
					}
					else if (r < 0.66)
					{
						batch->AddSprite(&m_objects.back()->transform, "cake2.png");
						m_objects.back()->transform.SetPosition(6, 0);
					}
					else
					{
						batch->AddSprite(&m_objects.back()->transform, "ham2.png");
						m_objects.back()->transform.SetPosition(8, 0);
					}
					m_objects.back()->transform.SetScale(r2);
					break;
				case 3:
					if (r < 0.33)
					{
						batch->AddSprite(&m_objects.back()->transform, "turkey2.png");
						m_objects.back()->transform.SetPosition(12, 22);
					}
					else if (r < 0.66)
					{
						batch->AddSprite(&m_objects.back()->transform, "cake1.png");
					}
					else
					{
						batch->AddSprite(&m_objects.back()->transform, "ham1.png");
					}
					m_objects.back()->transform.SetScale(r2);
					break;
				}
			}
		}
		break;
	case 4:
		m_state = 1;

		m_objects.push_back(new Object);
		parent->AddChild(m_objects.back());
		m_objects.back()->SetActive(false);
		m_objects.back()->transform.SetScale(Randomizer::GetFloat(0.5, 0.6));

		batch->AddSprite(&m_objects.back()->transform, "isammaa.png");
	}
}

void FoodComponent::DropState()
{
	SpriteBatch* batch = parent->Parent<SpriteBatch>();

	m_state--;

	float r = Randomizer::GetFloat();

	switch (m_type)
	{
	case 0:
		batch->RemoveSprite(&m_objects[m_state + 1]->transform);
		break;
	case 1:
	case 5:
		for (int i = 0; i < 3; i++)
		{
			batch->RemoveSprite(&m_objects[i]->transform);

			if (m_type == 1)
			{
				if (m_state > i)
					batch->AddSprite(&m_objects[i]->transform, "milkFull.png");
				else
					batch->AddSprite(&m_objects[i]->transform, "milkEmpty.png");
			}
			else
			{
				if (m_state > i)
					batch->AddSprite(&m_objects[i]->transform, "wineFull.png");
				else
					batch->AddSprite(&m_objects[i]->transform, "wineEmpty.png");
			}
		}
		if (r < 0.4)
		{
			m_objects[m_state]->transform.Rotate(-90);
			m_objects[m_state]->transform.SetOrigin({ -15, 15 });
		}
		else if (r < 0.8)
		{
			m_objects[m_state]->transform.Rotate(90);
			m_objects[m_state]->transform.SetOrigin({ 15, 15 });
		}

		break;
	case 2:
		batch->RemoveSprite(&m_objects[m_state + 1]->transform);
		break;
	case 3:
		batch->RemoveSprite(&m_objects[m_state + 1]->transform);
		break;
	case 4:
		batch->RemoveSprite(&m_objects[m_state]->transform);
		break;
	}
}
