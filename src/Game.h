#pragma once

#include "defines.h"
#include "EntityManager.h"

#include "miniaudio.h"

class Game
{
private:
	ma_engine* m_soundEngine;

	int m_gameStatus = STARTSCREENst;
	int m_lastGameStatus = NEWGAMEst;

	Entity* m_backgroundEntity	= nullptr;
	Entity* m_countdownEntity	= nullptr;
	Entity* m_enemyEntity		= nullptr;
	Entity* m_explosionEntity	= nullptr;
	Entity* m_gameoverEntity	= nullptr;
	Entity* m_healthbarEntity	= nullptr;
	Entity* m_helpscreenEntity	= nullptr;
	Entity* m_playerEntity		= nullptr;
	Entity* m_projectileEntity	= nullptr;
	Entity* m_scoreEntity		= nullptr;
	Entity* m_startscreenEntity = nullptr;

	bool directHit(Entity*, Entity*);

public:
	Game(EntityManager*, ma_engine*);
	~Game();

	int gameState() const;
	int lastGameState() const;
	void setGameState(int, int);

	void update(int, EntityManager*);

	void animateBackground(EntityManager*);
	void animateCountdown(EntityManager*);
	void animateEnemy(EntityManager*);
	void animateGameover(EntityManager*);
	void animateExplosions(EntityManager*);
	void animatePlayer(EntityManager*);
	void animateProjectiles(EntityManager*);

	void fireEnemyProjectile(EntityManager*);

	void checkCollisions(EntityManager*);

	void updateScore(EntityManager*);

	void respawnContestants(EntityManager*);

};