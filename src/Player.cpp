#include "Player.h"
#include <iostream>
#include "Math.h"


void Player::initialize() {
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setOutlineThickness(0.5f);

    size = sf::Vector2i(64, 64); // Set the size of the hitbox to match the sprite size
}

void Player::load() {
    
    if(texture.loadFromFile("/Users/jessysha/Desktop/rpg/assets/player/textures/spritesheet.png")){
        std::cout << "Player texture loaded successfully!" << std::endl;
    sprite.setTexture(texture);

    int xindex = 0;
    int yindex = 0;

    sprite.setTextureRect(sf::IntRect(xindex*size.x, yindex*size.y, size.x, size.y)); // Assuming each sprite is 64x64 pixels
    sprite.setPosition(sf::Vector2f(0, 0));
    sprite.scale(sf::Vector2f(1.5,1.5));

    hitbox.setSize(sf::Vector2f(size.x*sprite.getScale().x,size.y*sprite.getScale().y));
    }
    else{
        std::cout << "Failed to load player texture!" << std::endl;
    }
}
void Player::update(float deltaTime, Skeleton& skeleton) {

            sf::Vector2f pos = sprite.getPosition();

           if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))    
                sprite.setPosition(pos + sf::Vector2f(1,0) * playerSpeed * deltaTime); // Move right

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                sprite.setPosition(pos + sf::Vector2f(-1,0) * playerSpeed * deltaTime); // Move left

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                sprite.setPosition(pos + sf::Vector2f(0,-1) * playerSpeed * deltaTime); // Move up

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                sprite.setPosition(pos + sf::Vector2f(0,1) * playerSpeed * deltaTime); // Move down


                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

                sf::RectangleShape newbullet(sf::Vector2f(25, 12.5)); // Create a new bullet
                bullets.push_back(newbullet);

                int i = bullets.size() - 1; // Get the index of the new bullet
                bullets[i].setPosition(sprite.getPosition()); // Set the position of the new bullet to the player's position

            }
            for(size_t i = 0; i < bullets.size(); ++i){
                sf::Vector2f bulletdir = skeleton.sprite.getPosition() - bullets[i].getPosition();
                bulletdir = Math::normalizeVector(bulletdir); // Normalize the direction vector to get the unit vector
                bullets[i].setPosition(bullets[i].getPosition() + bulletdir * bulletspeed * deltaTime); // Move the bullet towards the skeleton
            }

            hitbox.setPosition(sprite.getPosition());

            if(Math::checkCollision(sprite.getGlobalBounds(),skeleton.sprite.getGlobalBounds())){
                std::cout << "Collision detected!" << std::endl;
            }
}
void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(hitbox);

    for(size_t i = 0; i < bullets.size(); ++i){
               window.draw(bullets[i]);
            }
}