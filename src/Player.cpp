#include "Player.h"
#include <iostream>
#include "Math.h"

void Player::load() {
    
    if(texture.loadFromFile("/Users/jessysha/Desktop/rpg/assets/player/textures/spritesheet.png")){
        std::cout << "Player texture loaded successfully!" << std::endl;
    sprite.setTexture(texture);

    int xindex = 0; // X index of the sprite in the spritesheet
    int yindex = 0; // Y index of the sprite in the spritesheet
    sprite.setTextureRect(sf::IntRect(xindex*64, yindex*64, 64, 64)); // Assuming each sprite is 64x64 pixels
    sprite.scale(sf::Vector2f(1.5,1.5)); // Scale the sprite to 2x its original size
    sprite.setPosition(sf::Vector2f(0, 0)); // Set initial position of the player sprite
    }
    else{
        std::cout << "Failed to load player texture!" << std::endl;
    }
}
void Player::initialize() {
    
}
void Player::update(Skeleton& skeleton) {

            sf::Vector2f pos = sprite.getPosition();

           if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))    
                sprite.setPosition(pos + sf::Vector2f(1,0)); // Move right

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                sprite.setPosition(pos + sf::Vector2f(-1,0)); // Move left

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                sprite.setPosition(pos + sf::Vector2f(0,-1)); // Move up

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                sprite.setPosition(pos + sf::Vector2f(0,1)); // Move down


                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                sf::RectangleShape newbullet(sf::Vector2f(25, 12.5)); // Create a new bullet
                bullets.push_back(newbullet);

                int i = bullets.size() - 1; // Get the index of the new bullet
                bullets[i].setPosition(sprite.getPosition()); // Set the position of the new bullet to the player's position

            }
            for(size_t i = 0; i < bullets.size(); ++i){
                sf::Vector2f bulletdir = skeleton.sprite.getPosition() - bullets[i].getPosition();
                bulletdir = Math::normalizeVector(bulletdir); // Normalize the direction vector to get the unit vector
                bullets[i].setPosition(bullets[i].getPosition() + bulletdir * bulletspeed); // Move the bullet towards the skeleton
            }
}
void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);

    for(size_t i = 0; i < bullets.size(); ++i){
               window.draw(bullets[i]);
            }
}