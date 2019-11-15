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
                                "Press a button below to continue";
    sf::String optionMenuString = "This is the Option Screen\n"
                                  "Press Back to go back";
    sf::String pauseMenuString = "Paused\n "
                                 "Press Back to go back\n"
                                 "Or press a button below to go to Main Menu";
    sf::String levelSelectMenuString = "This is the LevelSelect Screen\n"
                                       "Press a button for a level\n"
                                       "Or Press Back to go back";
    int characterSize = 28;
    float stringXPos = 0;
    float stringYPos = 0;

    float optionMenuButtonXPos = 400.0f;
    float optionMenuButtonYPos = 300.0f;

    float levelSelectMenuButtonXPos = 200.0f;
    float levelSelectMenuButtonYPos = 300.0f;

    float playGameButtonXPos = 300.0f;
    float playGameButtonYPos = 300.0f;

    float button1PauseMenuXPos = 300.0f;
    float button1PauseMenuYPos = 400.0f;

    float button1LevelSelectXPos = 200.0f;
    float button1LevelSelectYPos = 400.0f;
    float button2LevelSelectXPos = 300.0f;
    float button2LevelSelectYPos = 400.0f;
    float button3LevelSelectXPos = 400.0f;
    float button3LevelSelectYPos = 400.0f;

    float backButtonXPos = 700.0f;
    float backButtonYPos = 0.0f;

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


//    sf::Sprite operator == (sf::Sprite const &sprite) {
//
//    }




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
