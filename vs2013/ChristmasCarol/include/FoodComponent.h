#pragma once
#ifndef FOODCOMPONENT_H
#define FOODCOMPONENT_H

#include <UtH/UtHEngine.hpp>

class FoodComponent : public uth::Component
{
public:
	FoodComponent(int type);
	~FoodComponent();

	void Init() override;

	void DropState();

private:
	int m_type;
	int m_state;
	std::vector<uth::GameObject*> m_linkedObjects;

};

#endif
