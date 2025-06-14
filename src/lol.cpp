#include <SFML/Graphics.hpp>
#include <iostream>

// class Enemy{

//     public:
//         int dmg =0;
//         int hp = 0;
//         int attackSpeed =0;
//         std::string name = "";

//         void Kill(){
//             std::cout<< "im gonna kill you \n";
//         }

//         void heal(){
//             hp += 10;
//             std::cout<< "my health increased by 10 its now "<< hp<< '\n';
//         }

//         void walk(){
//             std::cout << "i am walking";
//         }


// };

int main()
{
    // Enemy goblin,dragon;
    // goblin.hp=100;
    // goblin.dmg=50;
    // dragon.hp=2000;
    // dragon.dmg=150;
    // goblin.walk();

    // std::cout<< "the goblin's stats are: \n";
    // std::cout<< "health: "<< goblin.hp<<'\n';
    // std::cout<<"damage: " << goblin.dmg << '\n';

    // std::cout<< "the dragon's stats are: \n";
    // std::cout<< "health: "<< dragon.hp<<'\n';
    // std::cout<<"damage: " << dragon.dmg << '\n';





    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}