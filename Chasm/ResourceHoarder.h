#pragma once
#include "Constants.h"
#include <SFML/Graphics.hpp>
class ResourceHoarder
{
public:
	ResourceHoarder();

	sf::Sprite& minerSprite(size_t id);
	sf::Sprite& minerBackgroundSprite(size_t id);
	sf::Sprite& shopBackgroundSprite();
	sf::Font& mainFont();

// Use arrays instead of vectors for textures and sprites because
// if a vector resizes it's copied and sprite no longer points to its texture
private:
	// Textures
	sf::Texture minerTextures_[MINER_FRAMES_CNT];
	sf::Texture minerBackgroundTextures_[MINER_BACKGROUNDS_CNT];
	sf::Texture shopBackgroundTexture_;

	// Sprites
	sf::Sprite minerSprites_[MINER_FRAMES_CNT];
	sf::Sprite minerBackgroundSprites_[MINER_BACKGROUNDS_CNT];
	sf::Sprite shopBackgroundSprite_;

	// Fonts
	sf::Font mainFont_;
};

