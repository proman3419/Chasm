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
        if (gui.checkIfClicked(gui.minerSprite()))
            gs.minerClicked();
        gui.showText("Depth:" + std::to_string(gs.depth()) + "\nLayer:" + std::to_string(gs.getDepthLayer()),
            TITLE_FONT_SIZE, sf::Color::Yellow,
            sf::Text::Bold, WINDOW_WIDTH / 64, WINDOW_HEIGHT / 64);

        // right side
        gui.showShopBackground();
        gui.showText("Rocks:" + std::to_string(gs.rocks()), TITLE_FONT_SIZE, sf::Color::Yellow,
            sf::Text::Bold, WINDOW_WIDTH / 2 + WINDOW_WIDTH / 64, WINDOW_HEIGHT / 64);

        std::string buyDigSpeedButtonLabel = "DIG SPEED\nlevel: " + std::to_string(gs.digSpeedLevel()) +
            "\nvalue: " + std::to_string(gs.digSpeed()) + "\nnext value: " + 
            std::to_string(gs.digSpeedNextLevelValue()) + "\ncost: " + 
            std::to_string(gs.digSpeedNextLevelCost());
        gui.showButton(buyDigSpeedButtonLabel,
            WINDOW_WIDTH / 2 + WINDOW_WIDTH / 64, WINDOW_HEIGHT / 10 + WINDOW_HEIGHT / 64,
            WINDOW_WIDTH / 64, WINDOW_HEIGHT / 64,
            WINDOW_WIDTH / 2 - WINDOW_WIDTH / 32, WINDOW_HEIGHT / 5, gui.buyDigSpeedButton());
        if (gui.checkIfClicked(gui.buyDigSpeedButton()))
            gs.buyDigSpeed();

        std::string buyDigClickMultiplierButtonLabel = "CLICK MULTIPLIER\nlevel: " + std::to_string(gs.digClickMultiplierLevel()) +
            "\nvalue: " + std::to_string(gs.digClickMultiplier()) + "\nnext value: " +
            std::to_string(gs.digClickMultiplierNextLevelValue()) + "\ncost: " +
            std::to_string(gs.digClickMultiplierNextLevelCost());
        gui.showButton(buyDigClickMultiplierButtonLabel,
            WINDOW_WIDTH / 2 + WINDOW_WIDTH / 64, (WINDOW_HEIGHT / 10 + 2*WINDOW_HEIGHT / 64) + WINDOW_HEIGHT / 5,
            WINDOW_WIDTH / 64, WINDOW_HEIGHT / 64,
            WINDOW_WIDTH / 2 - WINDOW_WIDTH / 32, WINDOW_HEIGHT / 5, gui.buyDigClickMultiplierButton());
        if (gui.checkIfClicked(gui.buyDigClickMultiplierButton()))
            gs.buyDigClickMultiplier();

        std::string buyDynamitePowerButtonLabel = "DYNAMITE POWER\nlevel: " + std::to_string(gs.dynamitePowerLevel()) +
            "\nvalue: " + std::to_string(gs.dynamitePower()) + "\nnext value: " +
            std::to_string(gs.dynamitePowerNextLevelValue()) + "\ncost: " +
            std::to_string(gs.dynamitePowerNextLevelCost());
        gui.showButton(buyDynamitePowerButtonLabel,
            WINDOW_WIDTH / 2 + WINDOW_WIDTH / 64, (WINDOW_HEIGHT / 10 + 3 * WINDOW_HEIGHT / 64) + 2 * (WINDOW_HEIGHT / 5),
            WINDOW_WIDTH / 64, WINDOW_HEIGHT / 64,
            WINDOW_WIDTH / 2 - WINDOW_WIDTH / 32, WINDOW_HEIGHT / 5, gui.buyDynamitePowerButton());
        if (gui.checkIfClicked(gui.buyDynamitePowerButton()))
            gs.buyDynamitePower();

        std::string buyDynamiteButtonLabel = "DYNAMITE\ncost: " +
            std::to_string(gs.dynamiteCost()) + "\nused: " + std::to_string(gs.dynamitesBought());
        gui.showButton(buyDynamiteButtonLabel,
            WINDOW_WIDTH / 2 + WINDOW_WIDTH / 64, (WINDOW_HEIGHT / 10 + 4 * WINDOW_HEIGHT / 64) + 3 * (WINDOW_HEIGHT / 5),
            WINDOW_WIDTH / 64, WINDOW_HEIGHT / 64,
            WINDOW_WIDTH / 2 - WINDOW_WIDTH / 32, WINDOW_HEIGHT / 5, gui.buyDynamiteButton());
        if (gui.checkIfClicked(gui.buyDynamiteButton()))
            if (gs.buyDynamite())
                gui.setExplosionShowing();

        // If explosion showing was set show the current frame of the animation
        gui.showExplosion();

        window.display();
        if (frameId != 0 && frameId % (2 * MINER_FRAMES_CNT) == 0)
            gs.minerCycleEnded();
        ++frameId;
    }

    return 0;
}
