#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

/*
DIVIDE ALL PIXELS BY TWO

TO GET THE CORRECT POSITIONING

BECAUSE MY MONITOR IS HALF THE SIZE OF THE TUTORIAL MONITOR

*/
sf::Vector2f normalizeVector(sf::Vector2f vector){
    float m = std::sqrt( vector.x* vector.x + vector.y* vector.y);
    sf::Vector2f normalizedVector;

    normalizedVector.x = vector.x / m;
    normalizedVector.y = vector.y / m;

    return normalizedVector;

};
int main()
{


    //____________________INITIALIZE____________________
        sf::ContextSettings settings;
        settings.antialiasingLevel =8; // Enable 8x antialiasing
        sf::RenderWindow window(sf::VideoMode(960, 540), "RPG Game", sf::Style::Default, settings);
    //____________________INITIALIZE____________________
    
    std::vector<sf::RectangleShape> bullets; // Vector to hold multiple bullets
    float bulletspeed = 0.5f; // Speed of the bullet
    //____________________LOAD__________________________
    //____________________SKELETON________________________

    sf::Texture skeleTexture;
    sf::Sprite skeleSprite;

    if(skeleTexture.loadFromFile("/Users/jessysha/Desktop/rpg/assets/skeleton/textures/spritesheet.png")){
        std::cout << "skeleton texture loaded successfully!" << std::endl;
    skeleSprite.setTexture(skeleTexture);
    skeleSprite.setPosition(sf::Vector2f(800,350)); // Set initial position of the skeleton sprite

    int xindex = 0; // X index of the sprite in the spritesheet
    int yindex = 2; // Y index of the sprite in the spritesheet
    skeleSprite.setTextureRect(sf::IntRect(xindex*64, yindex*64, 64, 64)); // Assuming each sprite is 64x64 pixels
    skeleSprite.scale(sf::Vector2f(1.5,1.5)); // Scale the sprite to 2x its original size
    }
    else{
        std::cout << "Failed to load skeleton texture!" << std::endl;
    }
    //____________________SKELETON________________________

    //____________________PLAYER________________________

    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if(playerTexture.loadFromFile("/Users/jessysha/Desktop/rpg/assets/player/textures/spritesheet.png")){
        std::cout << "Player texture loaded successfully!" << std::endl;
    playerSprite.setTexture(playerTexture);

    int xindex = 0; // X index of the sprite in the spritesheet
    int yindex = 0; // Y index of the sprite in the spritesheet
    playerSprite.setTextureRect(sf::IntRect(xindex*64, yindex*64, 64, 64)); // Assuming each sprite is 64x64 pixels
    playerSprite.scale(sf::Vector2f(1.5,1.5)); // Scale the sprite to 2x its original size
    playerSprite.setPosition(sf::Vector2f(0, 0)); // Set initial position of the player sprite
    }
    else{
        std::cout << "Failed to load player texture!" << std::endl;
    }
    //____________________PLAYER________________________
    //____________________LOAD__________________________


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

        sf::Vector2f pos = playerSprite.getPosition();
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))    
                playerSprite.setPosition(pos + sf::Vector2f(1,0)); // Move right

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                playerSprite.setPosition(pos + sf::Vector2f(-1,0)); // Move left

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                playerSprite.setPosition(pos + sf::Vector2f(0,-1)); // Move up

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                playerSprite.setPosition(pos + sf::Vector2f(0,1)); // Move down

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                sf::RectangleShape newbullet(sf::Vector2f(25, 12.5)); // Create a new bullet
                bullets.push_back(newbullet);

                int i = bullets.size() - 1; // Get the index of the new bullet
                bullets[i].setPosition(playerSprite.getPosition()); // Set the position of the new bullet to the player's position

            }
            for(size_t i = 0; i < bullets.size(); ++i){
                sf::Vector2f bulletdir = skeleSprite.getPosition() - bullets[i].getPosition();
                bulletdir = normalizeVector(bulletdir); // Normalize the direction vector to get the unit vector
                bullets[i].setPosition(bullets[i].getPosition() + bulletdir * bulletspeed); // Move the bullet towards the skeleton
            }
        //_____________ _______UPDATE____________________

        //_____________________DRAW_____________________
            window.clear(sf::Color::Black);
            window.draw(skeleSprite);
            window.draw(playerSprite);
            for(size_t i = 0; i < bullets.size(); ++i){
               window.draw(bullets[i]);
            }
            window.display();
        //_____________________DRAW_____________________
      
    }

    return 0;
}