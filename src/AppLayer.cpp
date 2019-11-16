//
// Created by 8luke on 10/25/2019.
//

#include "AppLayer.h"
#include <iostream>


AppLayer::AppLayer() {

    font.loadFromFile("..\\resources\\DS-DIGIT.TTF");
    hud.setFont(font);

}

bool AppLayer::mainMenu(sf::RenderWindow &App, bool &paused) {

    //set background color and string
    App.clear(sf::Color(mainMenuR, mainMenuG, mainMenuB));
    hud.setCharacterSize(characterSize);
    hud.setPosition(stringXPos,stringYPos);
    hud.setString(mainMenuString);
    App.draw(hud);

    //draw optionButton
    sf::Texture optionButton;
    sf::Sprite optionButtonImage;
    if (!optionButton.loadFromFile( "..\\resources\\button_template_options.png"))
        std::cout << "Can't find the option image" << std::endl;
    optionButtonImage.setPosition(optionMenuButtonXPos, optionMenuButtonYPos);
    optionButtonImage.setTexture(optionButton);
    App.draw(optionButtonImage);

    //draw levelSelectButton
    sf::Texture levelSelectButton;
    sf::Sprite levelSelectButtonImage;
    if (!levelSelectButton.loadFromFile( "..\\resources\\button_template_levelSelect.png"))
        std::cout << "Can't find the level image" << std::endl;
    levelSelectButtonImage.setPosition(levelSelectMenuButtonXPos, levelSelectMenuButtonYPos);
    levelSelectButtonImage.setTexture(levelSelectButton);
    App.draw(levelSelectButtonImage);

    //draw playButton
    sf::Texture playButton;
    sf::Sprite playButtonImage;
    if (!playButton.loadFromFile( "..\\resources\\button_template_playGame.png"))
        std::cout << "Can't find the play image" << std::endl;
    playButtonImage.setPosition(playGameButtonXPos, playGameButtonYPos);
    playButtonImage.setTexture(playButton);
    App.draw(playButtonImage);

    //optionButton clicked
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mouseLocation = sf::Mouse::getPosition(App);
        sf::Vector2f mouseLocF(static_cast<float>(mouseLocation.x), static_cast<float>(mouseLocation.y));
        if (optionButtonImage.getGlobalBounds().contains(mouseLocF)) {
            printf("Going to Option Menu...\n");
            optionMenuOpen = true;
            //while optionMenu is open
            while (optionMenuOpen) {
                sf::Event event;
                while (App.pollEvent(event)) {
                    //if you close out of the window
                    if (event.type == sf::Event::Closed) {
                        //break out of optionMenu loop
                        optionMenuOpen = false;
                        //break out of AppLayer loop
                        isPlaying = true;
                        //never enter main game loop
                        paused = true;
                        //close application
                        App.close();
                    }
                }
                optionMenu(App);
            }
        }
    }

    //levelSelect clicked
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mouseLocation = sf::Mouse::getPosition(App);
        sf::Vector2f mouseLocF(static_cast<float>(mouseLocation.x), static_cast<float>(mouseLocation.y));
        if (levelSelectButtonImage.getGlobalBounds().contains(mouseLocF)) {
            printf("Going to LevelSelect...\n");
            levelSelectOpen = true;
            while (levelSelectOpen) {
                sf::Event event;
                while (App.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed) {
                        levelSelectOpen = false;
                        isPlaying = true;
                        paused = true;
                        App.close();
                    }

                }
                levelSelectMenu(App);
            }
        }
    }

    //play clicked
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mouseLocation = sf::Mouse::getPosition(App);
        sf::Vector2f mouseLocF(static_cast<float>(mouseLocation.x), static_cast<float>(mouseLocation.y));
        if (playButtonImage.getGlobalBounds().contains(mouseLocF)) {
            isPlaying = true;
            loader.loadMap("level_tutorial.csv");
            level = loader.createLevelState();
        }
    }


    App.display();

    return isPlaying;
}

bool AppLayer::optionMenu(sf::RenderWindow &App) {

    //draw menu
    App.clear(sf::Color(optionMenuR, optionMenuG, optionMenuB));
    hud.setCharacterSize(characterSize);
    hud.setPosition(stringXPos,stringYPos);
    hud.setString(optionMenuString);
    App.draw(hud);

    //draw back button
    sf::Texture backButton;
    sf::Sprite backButtonImage;
    if (!backButton.loadFromFile( "..\\resources\\backButton.png"))
        std::cout << "Can't find the option image" << std::endl;
    backButtonImage.setPosition(backButtonXPos, backButtonYPos);
    backButtonImage.setTexture(backButton);
    App.draw(backButtonImage);


    //issue with back button: i would like to put all the buttons at the same y coordinates to be more
    //aestetically pleasing but whenever a button is pushed, it registers like 50 mouse clicks so
    //if I go from main to level select, it automatically presses the next button to go to level 1.
    //same with pause, if you go back to main menu by clicking button, it registers so many times that
    //by the time you make it to the main menu, the play button has already been clicked
    //in the mean time, i changed some problematic coordinates to 400 and some to 300 so they don't overlap

    //back clicked
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mouseLocation = sf::Mouse::getPosition(App);
        sf::Vector2f mouseLocF(static_cast<float>(mouseLocation.x), static_cast<float>(mouseLocation.y));
        if (backButtonImage.getGlobalBounds().contains(mouseLocF)) {
            printf("Going back to Main Menu...\n");
            optionMenuOpen = false;
            return optionMenuOpen;
        }
    }

    App.display();

    return optionMenuOpen;
}

bool AppLayer::pauseMenu(sf::RenderWindow &App, bool &paused) {

    //draw pause menu
    App.clear(sf::Color(pauseMenuR, pauseMenuG, pauseMenuB, pauseMenuAlpha));
    hud.setCharacterSize(characterSize);
    hud.setPosition(stringXPos,stringYPos);
    hud.setString(pauseMenuString);
    App.draw(hud);

    //draw back button
    sf::Texture backButton;
    sf::Sprite backButtonImage;
    if (!backButton.loadFromFile( "..\\resources\\backButton.png"))
        std::cout << "Can't find the option image" << std::endl;
    backButtonImage.setPosition(backButtonXPos, backButtonYPos);
    backButtonImage.setTexture(backButton);
    App.draw(backButtonImage);

    //draw mainMenu button
    sf::Texture button1;
    sf::Sprite buttonImage1;
    if (!button1.loadFromFile( "..\\resources\\button_template_mainMenu.png"))
        std::cout << "Can't find the image" << std::endl;
    buttonImage1.setPosition(button1PauseMenuXPos, button1PauseMenuYPos);
    buttonImage1.setTexture(button1);
    App.draw(buttonImage1);

    //back clicked
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mouseLocation = sf::Mouse::getPosition(App);
        sf::Vector2f mouseLocF(static_cast<float>(mouseLocation.x), static_cast<float>(mouseLocation.y));
        if (backButtonImage.getGlobalBounds().contains(mouseLocF)) {
            printf("returning to game...\n");
            pauseMenuOpen = false;
            return pauseMenuOpen;
        }
    }

    //mainMenu button clicked
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mouseLocation = sf::Mouse::getPosition(App);
        sf::Vector2f mouseLocF(static_cast<float>(mouseLocation.x), static_cast<float>(mouseLocation.y));
        if (buttonImage1.getGlobalBounds().contains(mouseLocF)) {
            printf("button clicked!\n");
            printf("going to main menu...\n");
            pauseMenuOpen = false;
            returnToMain = true;
            return pauseMenuOpen;
        }
    }
    App.display();
    return pauseMenuOpen;
}

bool AppLayer::levelSelectMenu(sf::RenderWindow &App) {

    //draw levelSelect menu
    App.clear(sf::Color(levelSelectR, levelSelectG, levelSelectB));
    hud.setCharacterSize(characterSize);
    hud.setPosition(stringXPos,stringYPos);
    hud.setString(levelSelectMenuString);
    App.draw(hud);

    //draw levelSelect buttons
    sf::Texture button1;
    sf::Sprite buttonImage1;
    sf::Texture button2;
    sf::Sprite buttonImage2;
    sf::Texture button3;
    sf::Sprite buttonImage3;
    if (!button1.loadFromFile( "..\\resources\\button_template.png"))
        std::cout << "Can't find the image" << std::endl;
    if (!button2.loadFromFile( "..\\resources\\button_template.png"))
        std::cout << "Can't find the image" << std::endl;
    if (!button3.loadFromFile( "..\\resources\\button_template.png"))
        std::cout << "Can't find the image" << std::endl;
    buttonImage1.setPosition(button1LevelSelectXPos, button1LevelSelectYPos);
    buttonImage1.setTexture(button1);
    App.draw(buttonImage1);
    buttonImage2.setPosition(button2LevelSelectXPos,button2LevelSelectYPos);
    buttonImage2.setTexture(button2);
    App.draw(buttonImage2);
    buttonImage3.setPosition(button3LevelSelectXPos,button3LevelSelectYPos);
    buttonImage3.setTexture(button3);
    App.draw(buttonImage3);

    //draw backButton
    sf::Texture backButton;
    sf::Sprite backButtonImage;
    if (!backButton.loadFromFile( "..\\resources\\backButton.png"))
        std::cout << "Can't find the option image" << std::endl;
    backButtonImage.setPosition(backButtonXPos, backButtonYPos);
    backButtonImage.setTexture(backButton);
    App.draw(backButtonImage);

    //if buttons are clicked
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mouseLocation = sf::Mouse::getPosition(App);
        sf::Vector2f mouseLocF(static_cast<float>(mouseLocation.x), static_cast<float>(mouseLocation.y));
        if (buttonImage1.getGlobalBounds().contains(mouseLocF)) {
            printf("button clicked!\n");
            levelSelectOpen = false;
            isPlaying = true;
            loader.loadMap("level_0_tutorial.txt");
            level = loader.createLevelState();
            printf("Going to level 1...\n");
            return levelSelectOpen;
        }
        if (buttonImage2.getGlobalBounds().contains(mouseLocF)) {
            printf("press the first button\n");
        }
        if (buttonImage3.getGlobalBounds().contains(mouseLocF)) {
            printf("press the first button\n");
        }
        if (backButtonImage.getGlobalBounds().contains(mouseLocF)) {
            printf("Going back to Main Menu...\n");
            levelSelectOpen = false;
            return levelSelectOpen;
        }
    }


    App.display();
    return levelSelectOpen;
}