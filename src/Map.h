#pragma once
#include <SFML/Graphics.hpp>
#include"Tile.h"

class Map {

private:
    sf::Texture tilesheettexture;

    Tile* tiles;

    int totalTiles;
    int tilewidth;
    int tileheight;

    int totaltileX;
    int totaltileY;

    int mapnum[6] = {120,121,122,
                    144,145,146};

    sf::Sprite mapsprite[6];
public:
    Map();
    ~Map();

    void load();
    void initialize();
    void draw(sf::RenderWindow& window);
    void update(double deltaTime);
};