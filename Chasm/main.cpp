#include "Constants.h"
#include "ResourceHoarder.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Chasm");
    window.setFramerateLimit(2);
    ResourceHoarder rh{};
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

        spriteHandle = rh.shopBackgroundSprite();
        spriteHandle.setPosition(WINDOW_WIDTH / 2, 0);
        window.draw(spriteHandle);

        window.display();
        ++frameId;
    }

    return 0;
}
