#include "Danger.h"
#include <CommonInfo.h>

Danger::Danger()
{
	positions.push_back({});
}

Danger::~Danger()
{
}

void Danger::update(float dt)
{
	const float time = CommonInfo::dangerTime += dt;
	if (time > 8) // change pos
	{
		CommonInfo::dangerTime = -2;
	}
	else if (time > 2) //activate
	{
		if (time < 3)
			transform.ScaleToSize(60 + (time - 2) * 600, 1200);
		else
			transform.ScaleToSize(60 + 600, 1200);
	}
	else if (time > 0)
	{
		if (time < 1)
			transform.ScaleToSize(60, (time)* 1200);
		else
			transform.ScaleToSize(60, 1200);

	}
}
