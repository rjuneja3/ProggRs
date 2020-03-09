#include  "SmallEnemy.h"
#include "Game.h"
#include "ScoreBoardManager.h"

SmallEnemy::SmallEnemy(int theYPosition)
	:Enemy(
	"../Assets/Ship_01/SmallEnemy.png",
	"smallEnemy",
	ENEMY, glm::vec2(Config::SCREEN_WIDTH, theYPosition))
{
	m_health = 5;
}

SmallEnemy::~SmallEnemy()
{
}

void SmallEnemy::update()
{
	if (getPosition().x >= Config::SCREEN_WIDTH * 0.8) {
		setPosition(glm::vec2((getPosition().x - 2), getPosition().y));
	}
	if(m_health <= 0)
	{
		setAlpha(0);
		setIsColliding(false);
		setPosition(glm::vec2(0.0f, -getHeight()));
	}
}

void SmallEnemy::decreaseHealth()
{
	m_health -= 1;
	if (m_health <= 0) {
		//increas the score when enemy dies
		ScoreBoardManager::Instance()->setScore(ScoreBoardManager::Instance()->getScore() + 300);
	}
}

void SmallEnemy::clean()
{
	
}

int SmallEnemy::getHealth()
{
	return m_health;
}
