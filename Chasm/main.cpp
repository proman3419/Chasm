#include "Constants.h"
#include "ResourceHoarder.h"
#include "GameState.h"
#include "GUI.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Chasm");
    window.setFramerateLimit(60);
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
        
        window.clear();
        
        // left side
        gui.showMinerBackground(0);
        gui.showMiner(frameId);
        if (gui.checkIfClicked(gui.minerSprite()))
            gs.minerClicked();
        gui.showText("Depth:" + std::to_string(gs.depth()) + "m", TITLE_FONT_SIZE, sf::Color::Yellow,
            sf::Text::Bold, WINDOW_WIDTH / 64, WINDOW_HEIGHT / 64);

        // right side
        gui.showShopBackground();

        window.display();
        gs.update();
        ++frameId;
    }

    return 0;
}
