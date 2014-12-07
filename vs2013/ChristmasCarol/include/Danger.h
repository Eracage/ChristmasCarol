#pragma once
#include <UtH/UtHEngine.hpp>

class Danger : public uth::GameObject
{
public:
	Danger();
	~Danger();

	void update(float dt) override;
private:
	float time;
	std::vector<pmath::Vec2> positions;

};
