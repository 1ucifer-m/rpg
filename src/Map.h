#pragma once
#include <SFML/Graphics.hpp>

class Map {

private:
    sf::Texture tilesheettexture;
    sf::Sprite sprite[10];

    int tilewidth;
    int tileheight;

    int totaltileX;
    int totaltileY;

public:
    Map();
    ~Map();

    void load();
    void initialize();
    void draw(sf::RenderWindow& window);
    void update(float deltaTime);
};