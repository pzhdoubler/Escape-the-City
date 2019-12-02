//
// Created by 8luke on 10/25/2019.
//

#ifndef CSCI437_APPLAYER_H
#define CSCI437_APPLAYER_H

#include <string>
#include "GameLogic.h"
#include "ScreenView.h"
#include "LevelState.h"
#include "LevelReader.h"

class AppLayer {

private:
    sf::Text hud;
    sf::Font font;
    sf::String mainMenuString = "Escape The City\n\n\n"
                                "Press a button below to continue";
    sf::String optionMenuString = "This is the Option Screen\n"
                                  "Press the rebind button to rebind a key\n"
                                  "Or press Back to go back";
    sf::String keyBindString = "Press the button you want to change\n";
    sf::String keyBindErrStr = "That key is already assigned.\n"
                               "Try pressing a key that is not bound my guy\n";
    sf::String keyBindChangeStr = "That key is assigned to something\n"
                               "What would you like to change it to?";
    sf::String keyBindSuccStr = "Key changed!\n";
    sf::String pauseMenuString = "Paused\n "
                                 "Press Back to go back\n"
                                 "Or press a button below to go to Main Menu";
    sf::String levelSelectMenuString = "This is the LevelSelect Screen\n"
                                       "Press a button for a level\n"
                                       "Or Press Back to go back";

    float mainStringXPos = 130;
    float mainStringYPos = 10;
    int characterSize = 42;
    float stringXPos = 0;
    float stringYPos = 0;


    sf::Texture mainbackground;
    sf::Texture levelbackground;

    float optionMenuButtonXPos = 528.0f;
    float optionMenuButtonYPos = 478.0f;

    float optionMenuRebindButtonXPos = 428.0f;
    float optionMenuRebindButtonYPos = 478.0f;

    float levelSelectMenuButtonXPos = 128.0f;
    float levelSelectMenuButtonYPos = 478.0f;

    float playGameButtonXPos = 328.0f;
    float playGameButtonYPos = 478.0f;

    float button1PauseMenuXPos = 328.0f;
    float button1PauseMenuYPos = 378.0f;

    float button1LevelSelectXPos = 28.0f;
    float button1LevelSelectYPos = 178.0f;
    float button2LevelSelectXPos = 228.0f;
    float button2LevelSelectYPos = 178.0f;
    float button3LevelSelectXPos = 428.0f;
    float button3LevelSelectYPos = 178.0f;
    float button4LevelSelectXPos = 628.0f;
    float button4LevelSelectYPos = 178.0f;

    float button5LevelSelectXPos = 28.0f;
    float button5LevelSelectYPos = 278.0f;
    float button6LevelSelectXPos = 228.0f;
    float button6LevelSelectYPos = 278.0f;
    float button7LevelSelectXPos = 428.0f;
    float button7LevelSelectYPos = 278.0f;
    float button8LevelSelectXPos = 628.0f;
    float button8LevelSelectYPos = 278.0f;

    float button9LevelSelectXPos = 28.0f;
    float button9LevelSelectYPos = 378.0f;
    float button10LevelSelectXPos = 228.0f;
    float button10LevelSelectYPos = 378.0f;
    float button11LevelSelectXPos = 428.0f;
    float button11LevelSelectYPos = 378.0f;
    float button12LevelSelectXPos = 628.0f;
    float button12LevelSelectYPos = 378.0f;

    float backButtonXPos = 658.0f;
    float backButtonYPos = 3.0f;


    bool keyBinding(sf::RenderWindow& App, sf::Sprite backButtonImage, bool& paused);
    //std::string fromKtoS(const sf::Keyboard::Key& k);
    std::vector<int> bindVectFast;
    std::vector<int> bindVectJump;
    std::vector<int> previousBinds;

    bool optionMenu(sf::RenderWindow& App, bool& paused);
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

	int num_levels = 12;
	int playable_levels[12]; //size must equal num_levels
	int latest_level;
	int cur_level;


//    sf::Sprite operator == (sf::Sprite const &sprite) {
//
//    }




public:

    bool isPlaying = false;
    bool returnToMain = false;

    AppLayer();

    bool mainMenu(sf::RenderWindow& App, bool& paused, Controller& controller, GameLogic& logic);
    bool pauseMenu(sf::RenderWindow& App, bool& paused);
	std::string getLevel(int index);
	bool completeLevel();
    bool pauseMenuOpen = false;

    LevelReader loader;
    LevelState level;

};

#endif //CSCI437_APPLAYER_H
