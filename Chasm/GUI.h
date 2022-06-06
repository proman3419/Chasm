#pragma once
#include "ResourceHoarder.h"
class GUI
{
public:
	GUI(sf::RenderWindow* window);

	void showMinerBackground(size_t id);
	void showShopBackground();
	void showMiner(unsigned long long frameId);
	bool checkIfClicked(sf::Sprite& sprite);
	void showText(std::string toShow, unsigned int fontSize, sf::Color color, sf::Uint32 style, 
		float x, float y);
	void showButton(std::string label, float x, float y, float xLabelOff, float yLabelOff, 
		float width, float height, sf::Sprite& spriteHolder);

	sf::Sprite& minerSprite() { return minerSprite_; }
	sf::Sprite& buyDigSpeedButton() { return buyDigSpeedButton_; }
	sf::Sprite& buyDigClickMultiplierButton() { return buyDigClickMultiplier_; }

private:
	sf::RenderWindow* windowPtr_;
	ResourceHoarder rh_;
	sf::Sprite minerSprite_;
	sf::Sprite buyDigSpeedButton_;
	sf::Sprite buyDigClickMultiplier_;
	sf::Clock clock;
};

