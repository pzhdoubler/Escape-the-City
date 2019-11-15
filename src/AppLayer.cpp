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

    //if you press spaceBar to play, break out of AppLayer loop and load level
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        isPlaying = true;
        loader.loadMap("level_tutorial.csv");
        level = loader.createLevelState();
    }

    //if you go to optionMenu
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
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

    App.display();

    return isPlaying;
}

bool AppLayer::optionMenu(sf::RenderWindow &App) {

    App.clear(sf::Color(optionMenuR, optionMenuG, optionMenuB));
    hud.setCharacterSize(characterSize);
    hud.setPosition(stringXPos,stringYPos);
    hud.setString(optionMenuString);
    App.draw(hud);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
        printf("Going back to Main Menu...\n");
        optionMenuOpen = false;
        return optionMenuOpen;
    }
    App.display();

    return optionMenuOpen;
}

bool AppLayer::pauseMenu(sf::RenderWindow &App, bool &paused) {
    App.clear(sf::Color(pauseMenuR, pauseMenuG, pauseMenuB, pauseMenuAlpha));

    hud.setCharacterSize(characterSize);
    hud.setPosition(stringXPos,stringYPos);
    hud.setString(pauseMenuString);
    App.draw(hud);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        printf("returning to game...\n");
        pauseMenuOpen = false;
        return pauseMenuOpen;
    }

    sf::Texture button1;
    sf::Sprite buttonImage1;
    if (!button1.loadFromFile( "..\\resources\\rsz_button_template.png"))
        std::cout << "Can't find the image" << std::endl;
    buttonImage1.setPosition(button1PauseMenuXPos, button1PauseMenuYPos);
    buttonImage1.setTexture(button1);
    App.draw(buttonImage1);

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
    App.clear(sf::Color(levelSelectR, levelSelectG, levelSelectB));

    hud.setCharacterSize(characterSize);
    hud.setPosition(stringXPos,stringYPos);
    hud.setString(levelSelectMenuString);
    App.draw(hud);

    sf::Texture button1;
    sf::Sprite buttonImage1;
    sf::Texture button2;
    sf::Sprite buttonImage2;
    sf::Texture button3;
    sf::Sprite buttonImage3;
    if (!button1.loadFromFile( "..\\resources\\rsz_button_template.png"))
        std::cout << "Can't find the image" << std::endl;
    if (!button2.loadFromFile( "..\\resources\\rsz_button_template.png"))
        std::cout << "Can't find the image" << std::endl;
    if (!button3.loadFromFile( "..\\resources\\rsz_button_template.png"))
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
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
        printf("Going back to Main Menu...\n");
        levelSelectOpen = false;
        return levelSelectOpen;
    }

    App.display();
    return levelSelectOpen;
}
