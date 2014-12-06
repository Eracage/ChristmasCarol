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
	GameLogic m_logic;
};

#endif
