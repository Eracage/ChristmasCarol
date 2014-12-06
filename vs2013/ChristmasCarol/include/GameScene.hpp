#pragma once
#ifndef GAMESCENE_H_UTH
#define GAMESCENE_H_UTH

#include <UtH/UtHEngine.hpp>
#include <GameLogic.h>

class GameScene : public uth::Scene
{
public:
	GameScene();
	~GameScene() override;
	
	bool Init() override;
	bool DeInit() override;
	
	void Update(float dt) override;
	//void Draw(RenderTarget& target, RenderAttributes attributes = RenderAttributes()) override;
private:
	CommonInfo m_info;
	GameLogic m_logic;

	uth::GameObject* m_santa;
	std::vector<pmath::Vec2> m_waypoints;
};

#endif
