#pragma once
#include <SFML/Graphics.hpp>
class framerate{

    private:
    sf::Text framerateText;
    sf::Font font;

    double timer;

    public:
        framerate();
        ~framerate();
        void load();
        void initialize();
        void draw(sf::RenderWindow& window);
        void update(double deltaTime);

};