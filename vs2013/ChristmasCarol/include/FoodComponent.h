#pragma once
#ifndef FOODCOMPONENT_H
#define FOODCOMPONENT_H

#include <UtH/UtHEngine.hpp>

class FoodComponent : public uth::Component
{
public:
	FoodComponent(int type);
	~FoodComponent();

	void DropState();

private:
	int type;
	int state;
	std::vector<uth::GameObject*> m_linkedObjects;

};

#endif
