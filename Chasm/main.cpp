#include "Constants.h"
#include "ResourceHoarder.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Chasm");
    window.setFramerateLimit(60);
    ResourceHoarder rh{};
    GameState gs{};
    sf::Sprite spriteHandle;
    unsigned long long frameId = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        spriteHandle = rh.minerBackgroundSprite(0);
        spriteHandle.setPosition(0, 0);
        window.draw(spriteHandle);
        
        size_t minerFrameId = frameId % (2 * MINER_FRAMES_CNT) < MINER_FRAMES_CNT ? 
            frameId % MINER_FRAMES_CNT :
            MINER_FRAMES_CNT - (frameId % MINER_FRAMES_CNT) - 1;
        spriteHandle = rh.minerSprite(minerFrameId);
        spriteHandle.setPosition(WINDOW_WIDTH / 8, WINDOW_WIDTH / 8);
        window.draw(spriteHandle);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            // transform the mouse position from window coordinates to world coordinates
            sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            // retrieve the bounding box of the sprite
            sf::FloatRect bounds = spriteHandle.getGlobalBounds();
            sf::FloatRect scaledBounds = sf::FloatRect(
                bounds.left, bounds.top,
                bounds.width * spriteHandle.getScale().x,
                bounds.height * spriteHandle.getScale().y);

            // hit test
            if (bounds.contains(mouse))
            {
                // mouse is on sprite!
                gs.minerClicked();
            }
        }

        sf::Text text;

        // select the font
        text.setFont(rh.mainFont()); // font is a sf::Font

        // set the string to display
        text.setString("Depth:" + std::to_string(gs.depth()) + "m");

        // set the character size
        text.setCharacterSize(TITLE_FONT_SIZE); // in pixels, not points!

        // set the color
        text.setFillColor(sf::Color::Yellow);

        // set the text style
        text.setStyle(sf::Text::Bold);
        text.setPosition(WINDOW_WIDTH / 64, WINDOW_HEIGHT / 64);
        window.draw(text);

        spriteHandle = rh.shopBackgroundSprite();
        spriteHandle.setPosition(WINDOW_WIDTH / 2, 0);
        window.draw(spriteHandle);

        window.display();
        gs.update();
        ++frameId;
    }

    return 0;
}
