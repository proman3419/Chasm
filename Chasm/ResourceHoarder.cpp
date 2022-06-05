#include "Constants.h"
#include "ResourceHoarder.h"

ResourceHoarder::ResourceHoarder()
{
	for (int i = 0; i < MINER_FRAMES_CNT; ++i)
	{
		std::string path = "img/miner/miner_" + std::to_string(i) + ".png";

		sf::Texture texture;
		texture.loadFromFile(path);
		texture.setRepeated(false);
		minerTextures_[i] = texture;

		sf::Sprite sprite;
		sprite.setTexture(minerTextures_[i]);
		const float scaleX = 5;
		const float textureRatio = texture.getSize().y / texture.getSize().x;
		sprite.setScale(scaleX, scaleX * textureRatio);
		minerSprites_[i] = sprite;
	}

	for (int i = 0; i < MINER_BACKGROUNDS_CNT; ++i)
	{
		std::string path = "img/miner_backgrounds/miner_background_" + std::to_string(i) + ".png";

		sf::Texture texture;
		texture.loadFromFile(path);
		texture.setRepeated(true);
		minerBackgroundTextures_[i] = texture;

		sf::Sprite sprite;
		sprite.setTexture(minerBackgroundTextures_[i]);
		sprite.setTextureRect(sf::IntRect(0, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT));
		minerBackgroundSprites_[i] = sprite;
	}

	sf::Texture texture;
	texture.loadFromFile("img/shop_background.png");
	texture.setRepeated(true);
	shopBackgroundTexture_ = texture;
	
	sf::Sprite sprite;
	sprite.setTexture(shopBackgroundTexture_);
	sprite.setTextureRect(sf::IntRect(0, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT));
	shopBackgroundSprite_ = sprite;

	mainFont_.loadFromFile("fonts/bescii.ttf");
}

sf::Sprite& ResourceHoarder::minerSprite(size_t id)
{
	return minerSprites_[id];
}

sf::Sprite& ResourceHoarder::minerBackgroundSprite(size_t id)
{
	return minerBackgroundSprites_[id];
}

sf::Sprite& ResourceHoarder::shopBackgroundSprite()
{
	return shopBackgroundSprite_;
}

sf::Font& ResourceHoarder::mainFont()
{
	return mainFont_;
}
