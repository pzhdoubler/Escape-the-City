//
// Created by 8luke on 10/25/2019.
//

#include "AppLayer.h"
#include <iostream>
#include <sstream>
#include <fstream>


AppLayer::AppLayer() {


    //trying to init level and screen outside of AppLayer and see if it still causes glitch, doesn't appear to be the case
    font.loadFromFile("..\\resources\\DS-DIGIT.TTF");
    hud.setFont(font);

}

bool AppLayer::screenTransitionTest(sf::RenderWindow& App) {


    App.clear(sf::Color(0,0,255));

    std::stringstream ss;
    ss << "This is the Start Screen";
    hud.setString(ss.str());
    App.draw(hud);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        isPaused = true;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        printf("howdy\n");
    }
    App.display();


    return isPaused;
}
