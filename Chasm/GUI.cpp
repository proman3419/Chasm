#include "GUI.h"
#include <iostream>

GUI::GUI(sf::RenderWindow* window)
{
	windowPtr_ = window;
}

void GUI::showMinerBackground(size_t id)
{
	sf::Sprite sprite = rh_.minerBackgroundSprite(id);
	sprite.setPosition(0, 0);
	windowPtr_->draw(sprite);
}

void GUI::showShopBackground()
{
	sf::Sprite sprite = rh_.shopBackgroundSprite();
	sprite.setPosition(WINDOW_WIDTH / 2, 0);
	windowPtr_->draw(sprite);
}

void GUI::showMiner(unsigned long long frameId)
{
	size_t minerFrameId = frameId % (2 * MINER_FRAMES_CNT) < MINER_FRAMES_CNT ?
		frameId % MINER_FRAMES_CNT :
		MINER_FRAMES_CNT - (frameId % MINER_FRAMES_CNT) - 1;
	sf::Sprite sprite = rh_.minerSprite(minerFrameId);
	sprite.setPosition(WINDOW_WIDTH / 8, WINDOW_WIDTH / 8);
	windowPtr_->draw(sprite);
    minerSprite_ = sprite;
}

bool GUI::checkIfClicked(sf::Sprite& sprite)
{
    if (clock.getElapsedTime().asMilliseconds() >= GUI_BREAK_TIME)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            auto mousePos = sf::Mouse::getPosition(*windowPtr_); // Mouse position relative to the window
            auto translatedPos = windowPtr_->mapPixelToCoords(mousePos); // Mouse position translated into world coordinates
            return sprite.getGlobalBounds().contains(translatedPos); // Rectangle-contains-point check
        }
    }
    return false;
}

void GUI::showText(std::string toShow, unsigned int fontSize, sf::Color color, sf::Uint32 style, float x, float y)
{
    sf::Text text;

    // select the font
    text.setFont(rh_.mainFont()); // font is a sf::Font

    // set the string to display
    text.setString(toShow);

    // set the character size
    text.setCharacterSize(fontSize); // in pixels, not points!

    // set the color
    text.setFillColor(color);

    // set the text style
    text.setStyle(style);
    text.setPosition(x, y);
    windowPtr_->draw(text);
}

void GUI::showButton(std::string label, float x, float y, float xLabelOff, float yLabelOff, float width, float height, sf::Sprite& spriteHolder)
{
    sf::Sprite sprite;
    sprite.setTexture(rh_.buttonBackgroundTexture());
    sprite.setTextureRect(sf::IntRect(0, 0, width, height));
    sprite.setPosition(x, y);
    windowPtr_->draw(sprite);
    showText(label, BUTTON_FONT_SIZE, sf::Color::Black, 0, x + xLabelOff, y + xLabelOff);
    spriteHolder = sprite;
}
