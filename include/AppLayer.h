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
    sf::String mainMenuString = "This is the Main Menu\n "
                                "Press O for options or L for Level Select";
    sf::String optionMenuString = "This is the Option Screen\n"
                                  "Press B to go back";
    sf::String pauseMenuString = "Paused\n "
                                 "Press SpaceBar to go back\n"
                                 "Or press a button below to go to Main Menu";
    sf::String levelSelectMenuString = "This is the LevelSelect Screen\n"
                                       "Press a button for a level\n"
                                       "Or Press B to go back";
    int characterSize = 28;
    float stringXPos = 0;
    float stringYPos = 0;

    float button1PauseMenuXPos = 300.0f;
    float button1PauseMenuYPos = 400.0f;

    float button1LevelSelectXPos = 200.0f;
    float button1LevelSelectYPos = 300.0f;
    float button2LevelSelectXPos = 300.0f;
    float button2LevelSelectYPos = 300.0f;
    float button3LevelSelectXPos = 400.0f;
    float button3LevelSelectYPos = 300.0f;

    bool optionMenu(sf::RenderWindow& App);
    bool optionMenuOpen = false;
    bool levelSelectMenu(sf::RenderWindow& App);
    bool levelSelectOpen = false;

    int mainMenuR = 0;
    int mainMenuG = 0;
    int mainMenuB = 255;

    int optionMenuR = 128;
    int optionMenuG = 56;
    int optionMenuB = 211;

    int pauseMenuR = 255;
    int pauseMenuG = 128;
    int pauseMenuB = 255;
    int pauseMenuAlpha = 128;

    int levelSelectR = 56;
    int levelSelectG = 211;
    int levelSelectB = 128;





public:

    bool isPlaying = false;
    bool returnToMain = false;

    AppLayer();

    bool mainMenu(sf::RenderWindow& App, bool& paused);
    bool pauseMenu(sf::RenderWindow& App, bool& paused);
    bool pauseMenuOpen = false;

    LevelReader loader;
    LevelState level;

};

#endif //CSCI437_APPLAYER_H
