#include"skeleton.h"
#include <iostream>

void Skeleton::load(){

    if(texture.loadFromFile("/Users/jessysha/Desktop/rpg/assets/skeleton/textures/spritesheet.png")){
        std::cout << "skeleton texture loaded successfully!" << std::endl;
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(800,350)); // Set initial position of the skeleton sprite

    int xindex = 0; // X index of the sprite in the spritesheet
    int yindex = 2; // Y index of the sprite in the spritesheet
    sprite.setTextureRect(sf::IntRect(xindex*64, yindex*64, 64, 64)); // Assuming each sprite is 64x64 pixels
    sprite.scale(sf::Vector2f(1.5,1.5)); // Scale the sprite to 2x its original size
    }
    else{
        std::cout << "Failed to load skeleton texture!" << std::endl;
    }
}
void Skeleton::initialize() {

}
void Skeleton::update() {

}
void Skeleton::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}