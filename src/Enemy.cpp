#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Enemy.h"
#include "VertexBuffers.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

float Enemy::getPosX() const
{
	return m_enemyPosX;
}

float Enemy::getPosY() const
{
	return m_enemyPosY;
}

void Enemy::setPosX(float x)
{
	m_enemyPosX = x;
}

void Enemy::setPosY(float y)
{
	m_enemyPosY = y;
}

void Enemy::updatePosX(float x)
{
	if (x > 0.0f) {
		if (m_enemyPosX + m_xOffset + x >= 1.0f) {
			m_enemyPosX -= x;
		}
		else {
			m_enemyPosX += x;
		}
	}

	if (x < 0.0f) {
		if (m_enemyPosX + x <= -1.0f) {
			m_enemyPosX = -1.0f;
		}
		else {
			m_enemyPosX += x;
		}
	}
}

void Enemy::updatePosY(float y)
{
	if (y > 0.0f) {
		if (m_enemyPosY + m_yOffset + y >= 1.0f) {
			m_enemyPosY -= y;
		}
		else {
			m_enemyPosY += y;
		}
	}

	if (y < 0.0f) {
		if (m_enemyPosY + y <= -0.7f) {
			m_enemyPosY = -0.7f;
		}
		else {
			m_enemyPosY += y;
		}
	}
}

void Enemy::init()
{
	updateEnemyVertices(m_enemyVertices);
}

void Enemy::updateEnemyVertices(float* enemyVertices)
{
	VertexBuffers::updateVertices(ENEMY, enemyVertices);
}

float* Enemy::calculateEnemyPosition()
{
	float newPosX = getPosX();
	float newPosY = getPosY();

	m_enemyVertices[0] = newPosX;					// quad LL
	m_enemyVertices[1] = newPosY;
	m_enemyVertices[2] = m_spriteXOrigin;			// text LL
	m_enemyVertices[3] = m_spriteYOrigin;

	m_enemyVertices[5] = newPosX + m_xOffset;		// quad LR
	m_enemyVertices[6] = newPosY;
	m_enemyVertices[7] = m_spriteXOrigin + m_spriteXOffset;
	m_enemyVertices[8] = m_spriteYOrigin;

	m_enemyVertices[10] = newPosX + m_xOffset;		// quad UR
	m_enemyVertices[11] = newPosY + m_yOffset;
	m_enemyVertices[12] = m_spriteXOrigin + m_spriteXOffset;
	m_enemyVertices[13] = m_spriteYOrigin + m_spriteYOffset;

	m_enemyVertices[15] = newPosX;					// quad UL
	m_enemyVertices[16] = newPosY + m_yOffset;
	m_enemyVertices[17] = m_spriteXOrigin;
	m_enemyVertices[18] = m_spriteYOrigin + m_spriteYOffset;

	return m_enemyVertices;
}

void Enemy::fireEngines()
{
	if (m_spriteXOrigin + m_spriteXOffset >= 1.0f) {
		m_spriteXOrigin = 0.0f;
	}
	else {
		m_spriteXOrigin += m_spriteXOffset;
	}

	m_enemyVertices[2] = m_spriteXOrigin;						// LLx
	m_enemyVertices[7] = m_spriteXOrigin + m_spriteXOffset;		// LRx
	m_enemyVertices[12] = m_spriteXOrigin + m_spriteXOffset;	// URx
	m_enemyVertices[17] = m_spriteXOrigin;						// ULx

	updateEnemyVertices(m_enemyVertices);
}







