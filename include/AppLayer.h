//
// Created by 8luke on 10/25/2019.
//

#ifndef CSCI437_APPLAYER_H
#define CSCI437_APPLAYER_H

#include "GameLogic.h"
#include "ScreenView.h"
#include "LevelState.h"
#include "LevelReader.h"

class AppLayer {

private:
    LevelReader loader;
    LevelState level;
    sf::Text hud;
    sf::Font font;



public:

    GameLogic logic;
    ScreenView screen;

    bool isPaused = false;
    AppLayer();
    bool screenTransitionTest(sf::RenderWindow& App);
};

#endif //CSCI437_APPLAYER_H
