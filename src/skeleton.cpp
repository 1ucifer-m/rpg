#include"skeleton.h"
#include <iostream>

void Skeleton::load(){

    if(texture.loadFromFile("/Users/jessysha/Desktop/rpg/assets/skeleton/textures/spritesheet.png")){
        std::cout << "skeleton texture loaded successfully!" << std::endl;
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(800,350)); // Set initial position of the skeleton sprite

    int xindex = 0; // X index of the sprite in the spritesheet
    int yindex = 2; // Y index of the sprite in the spritesheet
    sprite.setTextureRect(sf::IntRect(xindex*size.x, yindex*size.y, size.x, size.y)); // Assuming each sprite is 64x64 pixels
    sprite.scale(sf::Vector2f(1.5,1.5)); // Scale the sprite to 2x its original size

    hitbox.setSize(sf::Vector2f(size.x*sprite.getScale().x,size.y*sprite.getScale().y));
    }
    else{
        std::cout << "Failed to load skeleton texture!" << std::endl;
    }
}
void Skeleton::initialize() {

    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Blue);
    hitbox.setOutlineThickness(0.5f);

    size = sf::Vector2i(64, 64); // Set the size of the hitbox to match the sprite size

}
void Skeleton::update(float deltaTime) {

    hitbox.setPosition(sprite.getPosition());
}
void Skeleton::draw(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(hitbox);
}