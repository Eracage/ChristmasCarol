#pragma once
#ifndef GAMEOVERSCENE_H_UTH
#define GAMEOVERSCENE_H_UTH

#include <UtH/UtHEngine.hpp>

class GameOverScene : public uth::Scene
{
public:
	GameOverScene();
	~GameOverScene() override;
	
	bool Init() override;
	bool DeInit() override;
	
	void Update(float dt) override;
	//void Draw(RenderTarget& target, RenderAttributes attributes = RenderAttributes()) override;
	float time;
};

#endif
