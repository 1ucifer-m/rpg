#include"Map.h"
#include <iostream>

Map::Map(): tileheight(16), tilewidth(16), totaltileX(0), totaltileY(0){
    
}
Map::~Map() {

}

void Map::load() {
    if(tilesheettexture.loadFromFile("/Users/jessysha/Desktop/rpg/assets/world/prison/tilesheet.png")) {
        totaltileX = tilesheettexture.getSize().x/tilewidth;
        totaltileY = tilesheettexture.getSize().x/tileheight;

        std::cout << "world prison texture loaded successfully!" << std::endl;

        for(size_t i=0; i<10;i++){
            sprite[i].setTexture(tilesheettexture);
            sprite[i].setTextureRect(sf::IntRect(i * tilewidth , 0 * tileheight ,tilewidth, tileheight));
            sprite[i].setScale(sf::Vector2f(2.5,2.5));
            sprite[i].setPosition(sf::Vector2f(50 + tilewidth * 2.5* i,50));
        }
 
    } else {
        std::cout << "Failed to load prison world texture!" << std::endl;
    }
    
}
void Map::initialize() {
   
}
void Map::draw(sf::RenderWindow& window) {
    for (size_t i = 0; i < 10; i++){
     window.draw(sprite[i]); 
    }
    
    
}

void Map::update(float deltaTime) {
   
}