#pragma once
#ifndef MENUSCENE_H_UTH
#define MENUSCENE_H_UTH

#include <UtH/UtHEngine.hpp>

class MenuScene : public uth::Scene
{
public:
	MenuScene();
	~MenuScene() override;
	
	bool Init() override;
	bool DeInit() override;
	
	void Update(float dt) override;
	//void Draw(RenderTarget& target, RenderAttributes attributes = RenderAttributes()) override;
};

#endif
