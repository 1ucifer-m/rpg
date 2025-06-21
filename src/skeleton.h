#pragma once
#include <SFML/Graphics.hpp>

class Skeleton {

    private:
        sf::Texture texture;

    public:
        sf::Sprite sprite;
    public:

        void load();
        void initialize();
        void draw(sf::RenderWindow& window);
        void update();
};