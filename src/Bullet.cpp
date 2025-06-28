#include"Bullet.h"
#include"Math.h"

Bullet::Bullet() : speed(0) {
   
}
Bullet::~Bullet() {

}

void Bullet::initialize(const sf::Vector2f& pos, const sf::Vector2f& target, float speed) {
    this->speed = speed;
    shape.setSize(sf::Vector2f(25, 12.5)); 
    shape.setPosition(pos);
    direction = Math::normalizeVector(target - pos);
}

void Bullet::update(double deltaTime) {
   
    shape.setPosition(shape.getPosition() + direction * speed * (float)deltaTime);
}

void Bullet::draw(sf::RenderWindow& window) {
   window.draw(shape);
}
