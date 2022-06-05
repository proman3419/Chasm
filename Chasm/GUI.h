#pragma once
#include "ResourceHoarder.h"
class GUI
{
public:
	GUI(sf::RenderWindow* window);

	void showMinerBackground(size_t id);
	void showShopBackground();
	void showMiner(unsigned long long frameId);
	bool checkIfClicked(sf::Sprite sprite);
	void showText(std::string toShow, unsigned int fontSize, sf::Color color, sf::Uint32 style, float x, float y);

	sf::Sprite& minerSprite();

private:
	sf::RenderWindow* windowPtr_;
	ResourceHoarder rh_;
	sf::Sprite minerSprite_;
};

