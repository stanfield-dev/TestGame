#include "Renderer.h"

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <iostream>

void Renderer::init(unsigned int shaderProgram)
{
	glClearColor(0.0f, 0.2f, 0.1f, 1.0f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	m_projectionMatrix = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);

	m_projectionMatrixLoc = glGetUniformLocation(shaderProgram, "projectionMatrix");
	m_viewMatrixLoc = glGetUniformLocation(shaderProgram, "viewMatrix");

	glUniformMatrix4fv(m_projectionMatrixLoc, 1, GL_FALSE, glm::value_ptr(m_projectionMatrix));
	glUniformMatrix4fv(m_viewMatrixLoc, 1, GL_FALSE, glm::value_ptr(m_viewMatrix));
}

void Renderer::drawEntities(unsigned int shaderProgram, EntityManager* entityManager)
{
	glClear(GL_COLOR_BUFFER_BIT);

	for (auto entity : entityManager->getEntityRegistry()) {
		entity->bindVAO();
		entity->bindIBO();

		// background animation
		if (entity->getType() == BACKGROUND) {
			entity->scrollBackground();
		}

		// engine animation
		if (entity->getType() == PLAYER || entity->getType() == ENEMY) {
			entity->fireEngines();
		}

		// move enemy ship
		if (entity->getType() == ENEMY) {
			entity->moveEnemy();
		}

		// enemy fire at player
		if (entity->getType() == ENEMY && entityManager->getPlayerEntity() != nullptr) {
			Entity* player = entityManager->getPlayerEntity();

			if (rand() % 1000 < 10) {
				entityManager->spawnEntity(PROJECTILE, entity->getGunPositionX(), entity->getGunPositionY(), 0.0f, ENEMY,
					entity->getProjectileSourcePosition(), player->getProjectileTargetPosition());
			}
		}

		// move projectile across screen
		if (entity->getType() == PROJECTILE) {
			if (entity->getProjectileSource() == PLAYER) { // horizontal only
				entity->updatePositionX(0.03f);
			}
			else {
				entity->moveProjectile();
			}
		}

		// explosion animation
		if (entity->getType() == EXPLOSION) {
			if (entity->getExplosionFrame() > 24) {
				entityManager->removeEntityFromRegistry(entity);
				entity->~Entity();
			}
			else {
				entity->animateExplosion();
			}
		}

		// countdown animation
		if (entity->getType() == COUNTDOWN) {
			if (entity->getCountdownFrame() > 400) {
				if (entity->getCountdownSource() == ENEMY) {
					entityManager->respawnEnemy();
				}
				entityManager->removeEntityFromRegistry(entity);
				entity->~Entity();
			}
			else {
				entity->animateCountdown();
			}
		}

		entity->updateVertexBuffer();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		entity->unbindVAO();
	}
}

void Renderer::drawGameMenu(unsigned int shaderProgram, EntityManager* entityManager)
{
	glClear(GL_COLOR_BUFFER_BIT);

	for (auto entity : entityManager->getEntityRegistry()) {
		entity->bindVAO();
		entity->bindIBO();

		// game menu animation
		if (entity->getType() == GAME_MENU) {
			entity->animateMenu();
		}

		entity->updateVertexBuffer();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		entity->unbindVAO();
	}
}

void Renderer::drawHelpMenu(unsigned int shaderProgram, EntityManager* entityManager)
{
	glClear(GL_COLOR_BUFFER_BIT);

	for (auto entity : entityManager->getEntityRegistry()) {
		entity->bindVAO();
		entity->bindIBO();

		// help menu animation
		if (entity->getType() == HELP_MENU) {
			entity->animateMenu();
		}

		entity->updateVertexBuffer();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		entity->unbindVAO();
	}
}
