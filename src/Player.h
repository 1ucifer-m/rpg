#pragma once
#include <SFML/Graphics.hpp>
#include"skeleton.h"

class Player {

    private:
        sf::Texture texture;

        std::vector<sf::RectangleShape> bullets; // Vector to hold multiple bullets
        float bulletspeed = 0.5f; // Speed of the bullet

    public:
        sf::Sprite sprite;
    public:

        void load();
        void initialize();
        void draw(sf::RenderWindow& window);
        void update(Skeleton& skeleton);
};