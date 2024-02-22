#include <iostream>
#include <string>

#include <GL/glew.h>

#include "stb_image.h"

#include "Textures.h"
#include "Shader.h"


Textures::Textures()
{
}

Textures::~Textures()
{
}

void Textures::init(unsigned int shaderProgram)
{
	unsigned int loc0;

	loadTexture(PLAYER);
	loadTexture(ENEMY);
	loadTexture(PROJECTILE);
	loadTexture(EXPLOSION);
	loadTexture(GAME_MENU);
	loadTexture(HELP_MENU);
	loadTexture(COUNTDOWN);
	loadTexture(TERRAIN);
	loadTexture(BACKGROUND);

	loc0 = glGetUniformLocation(shaderProgram, "u_textures");
	int samplers[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 }; 
	glUniform1iv(loc0, 9, samplers);
}

void Textures::loadTexture(int type)
{ 
	if (type == BACKGROUND) {
		glCreateTextures(GL_TEXTURE_2D, 1, &m_backgroundTextureID);
		glBindTexture(GL_TEXTURE_2D, m_backgroundTextureID);

		loadImage(BACKGROUND_IMAGE);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_textureData);

		glBindTextureUnit(0, m_backgroundTextureID);
	}

	if (type == PLAYER) {
		glCreateTextures(GL_TEXTURE_2D, 1, &m_playerTextureID);
		glBindTexture(GL_TEXTURE_2D, m_playerTextureID);

		loadImage(PLAYER_SPRITE);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_textureData);

		glBindTextureUnit(1, m_playerTextureID);
	}

	if (type == ENEMY) {
		glCreateTextures(GL_TEXTURE_2D, 1, &m_enemyTextureID);
		glBindTexture(GL_TEXTURE_2D, m_enemyTextureID);

		loadImage(ENEMY_SPRITE);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_textureData);

		glBindTextureUnit(2, m_enemyTextureID);
	}

	if (type == TERRAIN) {
		glCreateTextures(GL_TEXTURE_2D, 1, &m_terrainTextureID);
		glBindTexture(GL_TEXTURE_2D, m_terrainTextureID);

		loadImage(TERRAIN_SPRITE);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_textureData);

		glBindTextureUnit(3, m_terrainTextureID);
	}

	if (type == PROJECTILE) {
		glCreateTextures(GL_TEXTURE_2D, 1, &m_projectileTextureID);
		glBindTexture(GL_TEXTURE_2D, m_projectileTextureID);

		loadImage(PROJECTILE_SPRITE);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_textureData);

		glBindTextureUnit(4, m_projectileTextureID);
	}

	if (type == EXPLOSION) {
		glCreateTextures(GL_TEXTURE_2D, 1, &m_explosionTextureID);
		glBindTexture(GL_TEXTURE_2D, m_explosionTextureID);

		loadImage(EXPLOSION_SPRITE);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_textureData);

		glBindTextureUnit(5, m_explosionTextureID);
	}

	if (type == GAME_MENU) {
		glCreateTextures(GL_TEXTURE_2D, 1, &m_menuTextureID);
		glBindTexture(GL_TEXTURE_2D, m_menuTextureID);

		loadImage(MENU_IMAGE);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_textureData);

		glBindTextureUnit(6, m_menuTextureID);
	}

	if (type == HELP_MENU) {
		glCreateTextures(GL_TEXTURE_2D, 1, &m_helpTextureID);
		glBindTexture(GL_TEXTURE_2D, m_helpTextureID);

		loadImage(HELP_IMAGE);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_textureData);

		glBindTextureUnit(7, m_helpTextureID);
	}

	if (type == COUNTDOWN) {
		glCreateTextures(GL_TEXTURE_2D, 1, &m_countdownTextureID);
		glBindTexture(GL_TEXTURE_2D, m_countdownTextureID);

		loadImage(COUNTDOWN_IMAGE);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_textureData);

		glBindTextureUnit(8, m_countdownTextureID);
	}

	if (m_textureData) {
		stbi_image_free(m_textureData);
	}
}

void Textures::loadImage(const std::string& path)
{
	stbi_set_flip_vertically_on_load(1);
	m_textureData = stbi_load(path.c_str(), &m_width, &m_height, &m_bpp, 4);

	if (m_textureData == nullptr)
		std::cout << "FAILED TO LOAD TEXTURE FILE: " << path << " " << stbi_failure_reason() << std::endl;
}




