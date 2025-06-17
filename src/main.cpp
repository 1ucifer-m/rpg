#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
        //____________________INITIALIZE____________________
        sf::ContextSettings settings;
        settings.antialiasingLevel =8; // Enable 8x antialiasing
        sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);

        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(sf::Vector2f(100,100)); // Set the position of the shape
        shape.setOutlineThickness(10);
        shape.setOutlineColor(sf::Color::Red);

        sf::RectangleShape rect(sf::Vector2f(100, 2));
        rect.setPosition(sf::Vector2f(100,100));
        rect.setFillColor(sf::Color::Blue);
        //rect.setOrigin(rect.getSize().x/2, rect.getSize().y/2); // Set the origin to the center of the rectangle
        //rect.setRotation(45); // Rotate the rectangle by 45 degrees
        rect.setOutlineThickness(5);
        rect.setOutlineColor(sf::Color::Yellow);

        sf::CircleShape triangle(50.f,3);
        sf::CircleShape square(50.f,4);
        sf::CircleShape pentagon(50.f,5);
    //____________________INITIALIZE____________________
    
        //main game loop
    while (window.isOpen())
    {
        //____________________UPDATE____________________
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        //____________________UPDATE____________________

        //_____________________DRAW_____________________
            window.clear(sf::Color::Black);
            window.draw(shape);
            window.draw(rect);
            //window.draw(triangle);
            //window.draw(square);
            //window.draw(pentagon);
            window.display();
        //_____________________DRAW_____________________
        }
      
    }

    return 0;
}