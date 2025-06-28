#include"Map.h"
#include <iostream>

Map::Map(): tileheight(16), tilewidth(16), totaltileX(0), totaltileY(0){
    
}
Map::~Map() {

}

void Map::load() {
    if(tilesheettexture.loadFromFile("/Users/jessysha/Desktop/rpg/assets/world/prison/tilesheet.png")) {
     
        std::cout << "world prison texture loaded successfully!" << std::endl;
 
        totaltileX = tilesheettexture.getSize().x/tilewidth;
        totaltileY = tilesheettexture.getSize().y/tileheight;

        totalTiles = totaltileX *  totaltileY;

        tiles = new Tile[totalTiles];

        for(size_t y=0; y<totaltileY; y++){
            for(size_t x=0; x<totaltileX; x++){

            int i= x+y * totaltileX;

            tiles[i].id = i;
            tiles[i].position= sf::Vector2i(x* tilewidth, y * tileheight);
        }
    }
    } else
        std::cout << "Failed to load prison world texture!" << std::endl;
    
     for(int y=0; y<2; y++){
        for(int x=0; x<3; x++){
            
            int i= x+y * 3;

            int index = mapnum[i];

            mapsprite[i].setTexture(tilesheettexture);
            mapsprite[i].setTextureRect(sf::IntRect(tiles[index].position.x,tiles[index].position.y,tilewidth,tileheight));
            mapsprite[i].setScale(sf::Vector2f(2.5, 2.5));
            mapsprite[i].setPosition(sf::Vector2f(x*16*2.5,100+y*16 *2.5));

        }
     }
}
void Map::initialize() {
   
}
void Map::draw(sf::RenderWindow& window) {

    for (size_t i = 0; i < 6; i++){
    window.draw(mapsprite[i]); 
    }
    
    
}

void Map::update(double deltaTime) {
   
}