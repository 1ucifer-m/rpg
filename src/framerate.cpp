#include "framerate.h"
#include <iostream>

framerate::framerate() : timer(0){

    std::cout << "Framerate object created." << std::endl;
}

framerate::~framerate() {
    std::cout << "Framerate object destroyed." << std::endl;
    
}
void framerate::load() {
    if(font.loadFromFile("/Users/jessysha/Desktop/rpg/assets/fonts/times.ttf")){
        std::cout << "Font loaded successfully!" << std::endl;
        framerateText.setFont(font);
    }
    else{
        std::cout << "Failed to load font!" << std::endl;
    }
}
void framerate::initialize() {

}
void framerate::draw(sf::RenderWindow& window) {
    window.draw(framerateText);
}
void framerate::update(double deltaTime) {

    timer += deltaTime;
    if(timer >= 100.0){
        double fps = 1000.0/ deltaTime;
         framerateText.setString("Frame Time: " + std::to_string((int)deltaTime) + " ms || FPS: " + std::to_string((int)fps));
        framerateText.setCharacterSize(15);
        timer = 0;

    }
}