#include <Button.hpp>

using namespace uth;

Button::Button(voidFunc onPressFunc, voidFunc onHoverFunc, voidFunc notContainedFunc)
	: m_pressFunc(onPressFunc),
	m_hoverFunc(onHoverFunc),
	m_notContained(notContainedFunc)
{
}

Button::~Button()
{
}

void Button::Init()
{
	if (parent->transform.GetSize() == pmath::Vec2())
	{
		parent->AddComponent(new Sprite(
			pmath::Vec4(Randomizer::GetFloat(), Randomizer::GetFloat(), Randomizer::GetFloat(), 0.45f),
			pmath::Vec2(40,40)
			));
	}
}

void Button::Update(float dt)
{
	const pmath::Vec2 pos = uthEngine.GetWindow().PixelToCoords(uthInput.Common.Position());
	const pmath::Rect box = parent->transform.GetGlobalBounds();
	if (box.contains(pos))
	{
		if (uthInput.Common == InputEvent::RELEASE)
			m_pressFunc();
		else
			m_hoverFunc();
	}
	else
	{
		m_notContained();
	}
}

void Button::SetSize(pmath::Vec2 size)
{
	pmath::Vec4 color = parent->GetComponent<Sprite>()->GetColor();
	parent->RemoveComponent(parent->GetComponent<Sprite>());

	parent->AddComponent(new Sprite(color,size));

	parent->transform.setSize(size);
}


