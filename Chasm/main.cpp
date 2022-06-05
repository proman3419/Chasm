#include "Constants.h"
#include "ResourceHoarder.h"
#include "GameState.h"
#include "GUI.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Chasm");
    GameState gs{};
    GUI gui{&window};
    unsigned long long frameId = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        unsigned int frameRate = std::min(gs.digSpeed() + ADDITIONAL_FRAMERATE, static_cast<unsigned int>(MAX_FRAMERATE));
        window.setFramerateLimit(frameRate);

        window.clear();
        
        // left side
        gui.showMinerBackground(gs.getDepthLayer());
        gui.showMiner(frameId);
        if (gui.checkIfClicked(gui.rh().minerSprite()))
            gs.minerClicked();
        gui.showText("Depth:" + std::to_string(gs.depth()), TITLE_FONT_SIZE, sf::Color::Yellow,
            sf::Text::Bold, WINDOW_WIDTH / 64, WINDOW_HEIGHT / 64);

        // right side
        gui.showShopBackground();
        gui.showText("Rocks:" + std::to_string(gs.rocks()), TITLE_FONT_SIZE, sf::Color::Yellow,
            sf::Text::Bold, WINDOW_WIDTH / 2 + WINDOW_WIDTH / 64, WINDOW_HEIGHT / 64);
        gui.showBuyDigSpeedButton();
        if (gui.checkIfClicked(gui.buyDigSpeedButton()))
            gs.buyDigSpeed();

        window.display();
        if (frameId != 0 && frameId % (2 * MINER_FRAMES_CNT) == 0)
            gs.minerCycleEnded();
        ++frameId;
    }

    return 0;
}
