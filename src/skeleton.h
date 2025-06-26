#pragma once
#include <SFML/Graphics.hpp>

class Skeleton {

    private:
        sf::Texture texture;

        sf::Text healthText;
        sf::Font font;


    public:
        sf::Sprite sprite;
        sf::RectangleShape hitbox;

        sf::Vector2i size;

        int health;

        
    public:

        Skeleton();
        ~Skeleton();

        void changehealth(int hp);

        void load();
        void initialize();
        void draw(sf::RenderWindow& window);
        void update(float deltaTime);
};