#include <SFML/Graphics.hpp>
#include<iostream>

#include "Player.h"
#include "Map.h"
#include "skeleton.h"
#include "framerate.h"

/*
DIVIDE ALL PIXELS BY TWO

TO GET THE CORRECT POSITIONING

BECAUSE MY MONITOR IS HALF THE SIZE OF THE TUTORIAL MONITOR

*/
int main()
{
    //____________________INITIALIZE____________________
        sf::ContextSettings settings;
        settings.antialiasingLevel =8; // Enable 8x antialiasing
        sf::RenderWindow window(sf::VideoMode(960, 540), "RPG Game", sf::Style::Default, settings);
        window.setFramerateLimit(120);
    //____________________INITIALIZE____________________
    



    Player player;
    Skeleton skeleton;
    framerate framerate;
    Map map;

    framerate.initialize();
    player.initialize();
    skeleton.initialize();
    map.initialize();


    framerate.load();
    player.load();
    skeleton.load();
    map.load();



    sf::Clock clock;

    while (window.isOpen()){

        sf::Time deltaTimeTimer = clock.restart();
        double deltaTime = deltaTimeTimer.asMicroseconds()/1000.0;
        //____________________UPDATE____________________
        sf::Event event;
        while(window.pollEvent(event)){

            if(event.type == sf::Event::Closed)
                window.close();
        }

            sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
            framerate.update(deltaTime);
            skeleton.update(deltaTime);
            map.update(deltaTime);
            player.update(deltaTime, skeleton, mousePos);

        //____________________UPDATE____________________
        //_____________________DRAW_____________________
            window.clear(sf::Color::Black);
            map.draw(window);
            skeleton.draw(window);
            player.draw(window);
            framerate.draw(window);
            window.display();

        //_____________________DRAW_____________________
    }
    return 0;
}