#include "Bullet.h"
#include "Game.h"
#include "Level1Scene.h"
#include "CollisionManager.h"


Bullet::Bullet()
{
	TheTextureManager::Instance()->load("../Assets/Sprites/Missile/Missile_1_Flying_000_Right.png",
		"Bullet", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("Bullet");
	setWidth(20);
	setHeight(20);
	//setPosition(glm::vec2(400.0f, 300.0f));
	setIsColliding(false);
	setType(BULLET);
	setSpeed(10.0f);
	setActive(false);
	m_alpha = 0;
	m_bulletPosition = MIDDLE;

}

Bullet::~Bullet() = default;

void Bullet::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	

	TheTextureManager::Instance()->draw("Bullet", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, m_alpha, true);
}

void Bullet::update()
{
	if (getPosition().x >= Config::SCREEN_WIDTH + getWidth())
	{
		reset();
	}
	if (isActive())
	{
		if(m_bulletPosition == TOP)
		{
			setPosition(glm::vec2((getPosition().x + getSpeed()), getPosition().y + getSpeed()/2));
		}else if(m_bulletPosition == BOTTOM)
		{
			setPosition(glm::vec2((getPosition().x + getSpeed()), getPosition().y - getSpeed()/2));
		}
		else if(m_bulletPosition == MIDDLE)
		{
			setPosition(glm::vec2((getPosition().x + getSpeed()), getPosition().y));
		}
	}
	if(m_pComet != nullptr)
	{
		//Collision::squaredRadiusCheck(this, m_pComet);
	}
}

void Bullet::setComet(Comet* pcomet)
{
	m_pComet = pcomet;
}

void Bullet::reset()
{
	setIsColliding(false);
	setPosition(glm::vec2(-getWidth(), -getHeight()));
	setActive(false);
	m_alpha = 0;
}


void Bullet::clean()
{
	//reset();
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
	setIsColliding(false);
	m_alpha = 255;
	setPosition(position);
	draw();
	setActive(true);
}

void Bullet::fire(glm::vec2 position, BulletPosition bulletPosition)
{
	m_bulletPosition = bulletPosition;
	setIsColliding(false);
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
