#pragma once
#include <SFML/Graphics.hpp>
#include"skeleton.h"
#include "Bullet.h"

class Player {

    private:
        sf::Texture texture;

        std::vector<Bullet> bullets; // Vector to hold multiple bullets

        float maxFireRate;
        float fireRateTimer;

        float playerSpeed;

        sf::RectangleShape hitbox;

        sf::Vector2i size;

    public:
        sf::Sprite sprite;
    public:

        Player();
        ~Player();

        void load();
        void initialize();
        void draw(sf::RenderWindow& window);
        void update(float deltaTime,Skeleton& skeleton, sf::Vector2f& mousePos);
};