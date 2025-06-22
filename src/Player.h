#pragma once
#include <SFML/Graphics.hpp>
#include"skeleton.h"

class Player {

    private:
        sf::Texture texture;

        std::vector<sf::RectangleShape> bullets; // Vector to hold multiple bullets
        float bulletspeed = 0.25f; // Speed of the bullet
        float playerSpeed = .5f; // Speed of the player

        sf::RectangleShape hitbox;

        sf::Vector2i size;

    public:
        sf::Sprite sprite;
    public:

        void load();
        void initialize();
        void draw(sf::RenderWindow& window);
        void update(float deltaTime,Skeleton& skeleton);
};