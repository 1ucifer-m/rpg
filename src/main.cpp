#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //____________________INITIALIZE____________________
        sf::ContextSettings settings;
        settings.antialiasingLevel =8; // Enable 8x antialiasing
        sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);
    //____________________INITIALIZE____________________
    
    //____________________LOAD________________________

    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if(playerTexture.loadFromFile("/Users/jessysha/Desktop/rpg/assets/player/textures/spritesheet.png")){
        std::cout << "Player texture loaded successfully!" << std::endl;
    playerSprite.setTexture(playerTexture);

    int xindex = 0; // X index of the sprite in the spritesheet
    int yindex = 0; // Y index of the sprite in the spritesheet
    playerSprite.setTextureRect(sf::IntRect(xindex*64, yindex*64, 64, 64)); // Assuming each sprite is 64x64 pixels
    playerSprite.scale(2.0f, 2.0f); // Scale the sprite to 2x its original size
    }
    else{
        std::cerr << "Failed to load player texture!" << std::endl;
    }

    //____________________LOAD________________________

        //main game loop
    while (window.isOpen())
    {
        //____________________UPDATE____________________
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
            /*if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::D){
                sf::Vector2f pos = playerSprite.getPosition();

                playerSprite.setPosition(pos + sf::Vector2f(10,0)); // Move up
                }
            }*/

        sf::Vector2f pos = playerSprite.getPosition();
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))    
                playerSprite.setPosition(pos + sf::Vector2f(1,0)); // Move right

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                playerSprite.setPosition(pos + sf::Vector2f(-1,0)); // Move left

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                playerSprite.setPosition(pos + sf::Vector2f(0,-1)); // Move up

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                playerSprite.setPosition(pos + sf::Vector2f(0,1)); // Move down
        //_____________ _______UPDATE____________________

        //_____________________DRAW_____________________
            window.clear(sf::Color::Black);
            // Draw the player sprite
            window.draw(playerSprite);
            window.display();
        //_____________________DRAW_____________________
      
    }

    return 0;
}