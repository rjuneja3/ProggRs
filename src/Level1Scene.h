#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"

#include "ship.h"
#include "Bullet.h"
#include "Background.h"
#include "Background1.h"
#include "Comet.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();

	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();
	

private:
	// game objects

	glm::vec2 m_mousePosition;


	Ship* m_pShip;
	Bullet* m_pBullet;
	Background* m_pBackground;
	Background1* m_pBackground1;
	Comet* m_pComet;
};

#endif /* defined (__LEVEL_1_SCENE__) */
