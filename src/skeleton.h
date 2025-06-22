#pragma once
#include <SFML/Graphics.hpp>

class Skeleton {

    private:
        sf::Texture texture;

    public:
        sf::Sprite sprite;

        sf::RectangleShape hitbox;

        sf::Vector2i size;
    public:

        void load();
        void initialize();
        void draw(sf::RenderWindow& window);
        void update(float deltaTime);
};