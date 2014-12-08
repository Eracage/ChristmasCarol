#include "Danger.h"
#include <CommonInfo.h>
#include <UtH/UtHEngine.hpp>

using namespace uth;

Danger::Danger()
	: doorOpen(false)
{
}

Danger::~Danger()
{
}

bool Danger::Init()
{
	positions.push_back({ 330, -600 });
	rotations.push_back(165);
	pos.push_back(3);

	positions.push_back({ 1000, 230 });
	rotations.push_back(-102);
	pos.push_back(5);

	positions.push_back({ -330, 600 });
	rotations.push_back(-15);
	pos.push_back(7);

	positions.push_back({ -1000, -230 });
	rotations.push_back(78);
	pos.push_back(1);

	AddComponent(new uth::Sprite("lightBeam.png"));
	transform.SetOrigin(2);
	transform.ScaleToSize(0, 0);

	Parent()->AddChild(doorParent = new GameObject);
	doorParent->AddChild(door = new GameObject);

	door->AddComponent(new Sprite("door.png"));
	door->transform.SetPosition(300, 100);
	door->transform.SetScale(0.5);
	door->transform.SetOrigin(2);
	return true;
}

void Danger::update(float dt)
{
	const float time = CommonInfo::dangerTime += dt;

	const float doorDefault = -75;
	const float doorMin = 20;
	const float doorMax = 30;

	if (time > 8) // change pos
	{
		if (doorOpen)
		{
			uthRS.LoadSound("door_close.wav")->Play();
			doorOpen = !doorOpen;
		}

		int r = rand() % 4;
		transform.SetPosition(positions[r]);
		transform.SetRotation(rotations[r]);
		doorParent->transform.SetPosition(positions[r]);
		doorParent->transform.SetRotation(rotations[r]);
		door->transform.SetRotation(doorDefault);
		CommonInfo::dangerPos = pos[r];
		CommonInfo::dangerTime = -2;
		transform.ScaleToSize(0, 0);
		doorOpen = false;
	}
	else if (time > 2) //activate
	{
		if (time < 3)
		{
			transform.ScaleToSize(60 + (time - 2) * 800, 2000);
			door->transform.SetRotation(doorDefault + doorMin + (time - 2) * doorMax);
		}
		else
		{
			transform.ScaleToSize(60 + 800, 2000);
			door->transform.SetRotation(doorDefault + doorMin + doorMax);
		}
	}
	else if (time > 0)
	{
		if (!doorOpen)
		{
			uthRS.LoadSound("door_open.wav")->Play();
			doorOpen = !doorOpen;
		}

		if (time < 1)
		{
			transform.ScaleToSize(60, (time)* 2000);
			door->transform.SetRotation(doorDefault + (time)* doorMin);
		}
		else
		{
			transform.ScaleToSize(60, 2000);
			door->transform.SetRotation(doorDefault + doorMin);
		}

	}
}
