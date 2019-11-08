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
    sf::Text hud;
    sf::Font font;
    bool optionMenu(sf::RenderWindow& App);
    bool optionMenuOpen = false;
    bool levelSelectMenu(sf::RenderWindow& App);
    bool levelSelectOpen = false;




public:

    GameLogic logic;
    ScreenView screen;

    bool isPlaying = false; //will change to isPlaying
    bool returnToMain = false; //will be activated on pause menu button press to go back to main

    AppLayer();
    bool mainMenu(sf::RenderWindow& App, bool& paused); //will change to mainMenu
    bool pauseMenu(sf::RenderWindow& App, bool& paused);
    bool pauseMenuOpen = false;

    LevelReader loader;
    LevelState level;

};

#endif //CSCI437_APPLAYER_H
