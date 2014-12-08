#pragma once
#include <UtH/UtHEngine.hpp>

class Danger : public uth::GameObject
{
public:
	Danger();
	~Danger();

	bool Init();

	void update(float dt) override;
private:
	float time;
	std::vector<pmath::Vec2> positions;
	std::vector<float> rotations;
	std::vector<float> pos;

	bool doorOpen;


	uth::GameObject* doorParent;
	uth::GameObject* door;
};
