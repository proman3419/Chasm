#include "GUI.h"

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

bool GUI::checkIfClicked(sf::Sprite sprite)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        // transform the mouse position from window coordinates to world coordinates
        sf::Vector2f mouse = windowPtr_->mapPixelToCoords(sf::Mouse::getPosition(*windowPtr_));

        // retrieve the bounding box of the sprite
        sf::FloatRect bounds = sprite.getGlobalBounds();
        sf::FloatRect scaledBounds = sf::FloatRect(
            bounds.left, bounds.top,
            bounds.width * sprite.getScale().x,
            bounds.height * sprite.getScale().y);

        // hit test
        if (bounds.contains(mouse))
        {
            // mouse is on sprite!
            return true;
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

sf::Sprite& GUI::minerSprite()
{
    return minerSprite_;
}
