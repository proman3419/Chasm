#pragma once
#include "ResourceHoarder.h"
class GUI
{
public:
	GUI(sf::RenderWindow* window);

	void showMinerBackground(size_t id);
	void showShopBackground();
	void showMiner(unsigned long long frameId);
	void showBuyDigSpeedButton();
	bool checkIfClicked(sf::Sprite sprite);
	void showText(std::string toShow, unsigned int fontSize, sf::Color color, sf::Uint32 style, float x, float y);

	ResourceHoarder& rh();
	sf::Sprite& buyDigSpeedButton();
	//sf::Sprite& buyDigClickMultiplier();

private:
	sf::RenderWindow* windowPtr_;
	ResourceHoarder rh_;
	sf::Sprite buyDigSpeedButton_;
	sf::Sprite buyDigClickMultiplier_;
};

