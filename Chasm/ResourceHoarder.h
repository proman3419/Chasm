#pragma once
#include "Constants.h"
#include <SFML/Graphics.hpp>
class ResourceHoarder
{
public:
	ResourceHoarder();

	sf::Texture& buttonBackgroundTexture() { return buttonBackgroundTexture_; }
	sf::Sprite& minerSprite(size_t id) { return minerSprites_[id]; }
	sf::Sprite& minerBackgroundSprite(size_t id) { return minerBackgroundSprites_[id]; }
	sf::Sprite& shopBackgroundSprite() { return shopBackgroundSprite_; }
	sf::Sprite& explosionSprite(size_t id) { return explosionSprites_[id]; }
	sf::Font& mainFont() { return mainFont_; }

// Use arrays instead of vectors for textures and sprites because
// if a vector resizes it's copied and sprite no longer points to its texture
private:
	// Textures
	sf::Texture minerTextures_[MINER_FRAMES_CNT];
	sf::Texture minerBackgroundTextures_[MINER_BACKGROUNDS_CNT];
	sf::Texture explosionTextures_[EXPLOSION_FRAMES_CNT];
	sf::Texture shopBackgroundTexture_;
	sf::Texture buttonBackgroundTexture_;

	// Sprites
	sf::Sprite minerSprites_[MINER_FRAMES_CNT];
	sf::Sprite minerBackgroundSprites_[MINER_BACKGROUNDS_CNT];
	sf::Sprite explosionSprites_[EXPLOSION_FRAMES_CNT];
	sf::Sprite shopBackgroundSprite_;

	// Fonts
	sf::Font mainFont_;
};

