#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
    sf::RectangleShape shape;
    sf::Vector2f direction;
    float speed;

public:

     Bullet();
     ~Bullet();

    void initialize(const sf::Vector2f& pos, const sf::Vector2f& target, float speed);
    void draw(sf::RenderWindow& window);
    void update(double deltaTime);

    inline const sf::FloatRect getGlobalBounds() const {

        return shape.getGlobalBounds();
    }
};
