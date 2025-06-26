#include "Player.h"
#include <iostream>
#include "Math.h"


Player::Player() :playerSpeed(.5f),maxFireRate(150),fireRateTimer(0.0f){
    
}

Player::~Player() {
    
}
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
void Player::update(float deltaTime, Skeleton& skeleton, sf::Vector2f& mousePos) {

            sf::Vector2f pos = sprite.getPosition();

           if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))    
                sprite.setPosition(pos + sf::Vector2f(1,0) * playerSpeed * deltaTime); // Move right

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                sprite.setPosition(pos + sf::Vector2f(-1,0) * playerSpeed * deltaTime); // Move left

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                sprite.setPosition(pos + sf::Vector2f(0,-1) * playerSpeed * deltaTime); // Move up

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                sprite.setPosition(pos + sf::Vector2f(0,1) * playerSpeed * deltaTime); // Move down


                //___________________________________________________________________________________________
               fireRateTimer += deltaTime;
                
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && fireRateTimer >= maxFireRate){
               
                bullets.push_back(Bullet());

                int i = bullets.size() - 1;
                bullets[i].initialize(sprite.getPosition(), mousePos, 0.25f);
                fireRateTimer =0;
            }
 
        for(size_t i = 0; i < bullets.size(); ++i){  
            bullets[i].update(deltaTime);
            if(skeleton.health >0){

                if(Math::checkCollision(bullets[i].getGlobalBounds(),skeleton.sprite.getGlobalBounds())){
                        
                    skeleton.changehealth(-10);    
                    bullets.erase(bullets.begin()+i);
                }
            }
        }

            hitbox.setPosition(sprite.getPosition());

            //____________________________________________________________________________________________
}
void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(hitbox);

    for(size_t i = 0; i < bullets.size(); ++i){
               bullets[i].draw(window); 
            }
}