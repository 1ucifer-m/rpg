#include <SFML/Graphics.hpp>
#include<iostream>

#include "Player.h"
#include "skeleton.h"

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

    player.initialize();
    skeleton.initialize();
    player.load();
    skeleton.load();


    sf::Clock clock;

    while (window.isOpen()){


        sf::Time deltaTimeTimer = clock.restart();
        float deltaTime = deltaTimeTimer.asMilliseconds();

        //____________________UPDATE____________________
        sf::Event event;
        while(window.pollEvent(event)){

            if(event.type == sf::Event::Closed)
                window.close();
        }


            skeleton.update(deltaTime);
            player.update(deltaTime, skeleton);
        //____________________UPDATE____________________
        //_____________________DRAW_____________________
            window.clear(sf::Color::Black);
            skeleton.draw(window);
            player.draw(window);
            window.display();

        //_____________________DRAW_____________________
    }
    return 0;
}