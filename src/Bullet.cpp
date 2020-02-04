#include "Bullet.h"
#include "Game.h"
#include "Level1Scene.h"


Bullet::Bullet()
{
	TheTextureManager::Instance()->load("../Assets/textures/Mine.png",
		"mineBullet", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("mineBullet");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(400.0f, 300.0f));
	setType(BULLET);
	setSpeed(10.0f);
	setActive(false);
	m_alpha = 255;
}

Bullet::~Bullet()
{
}

void Bullet::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("mineBullet", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, m_alpha, true);
}

void Bullet::update()
{
	if (getPosition().x >= 799)
	{
		setActive(false);
		m_alpha = 0;
	}
	if (isActive())
	{
		setPosition(glm::vec2((getPosition().x + getSpeed()), getPosition().y));
	}


}

void Bullet::clean()
{
}

void Bullet::setActive(bool active)
{
	m_isActive = active;
}

bool Bullet::isActive()
{
	return m_isActive;
}

void Bullet::fire(glm::vec2 position)
{
	m_alpha = 255;
	setPosition(position);
	draw();
	setActive(true);
}

void Bullet::setSpeed(float newSpeed)

{
	m_speed = newSpeed;
}

float Bullet::getSpeed()
{
	return m_speed;
}

void Bullet::checkBounds()
{
	if (getPosition().x > Config::SCREEN_WIDTH)
	{
		setPosition(glm::vec2(0.0f, getPosition().y));
	}
}
