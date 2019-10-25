//
// Created by 8luke on 10/25/2019.
//

#include "AppLayer.h"
#include <iostream>


AppLayer::AppLayer() {

    //load map
    loader.loadMap("level_prototype.txt");

    //receive level
    level = loader.createLevelState();

    //init logic and screen
    logic.init(level);
    screen.init(level);

}

bool AppLayer::screenTransitionTest(sf::RenderWindow& App) {
    while (isPaused == false) {
        App.clear(sf::Color(0,0,255));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            isPaused = true;
        }
        App.display();
    }

    return isPaused;
}
