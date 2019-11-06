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

bool AppLayer::mainMenu(sf::RenderWindow &App, bool &paused) {


    App.clear(sf::Color(0,0,255));

    std::stringstream ss;
    ss << "This is the Main Menu. Press O for options, or L for Level Select";
    hud.setString(ss.str());
    App.draw(hud);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        isPlaying = true;
        loader.loadMap("level_0_tutorial.txt");
        //recieve level and initialize Views
        level = loader.createLevelState();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
        printf("Going to Option Menu...\n");
        optionMenuOpen = true;
        while (optionMenuOpen) {
            sf::Event event;
            while (App.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    optionMenuOpen = false;
                    isPlaying = true;
                    paused = true;
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
    App.clear(sf::Color(128, 56, 211));

    std::stringstream ss;
    ss << "This is the Option Screen. Press B to go back";
    hud.setString(ss.str());
    App.draw(hud);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
        printf("Going back to Main Menu...\n");
        optionMenuOpen = false;
        return optionMenuOpen;
    }
    App.display();


    return optionMenuOpen;
}

bool AppLayer::levelSelectMenu(sf::RenderWindow &App) {
    App.clear(sf::Color(56, 211, 128));

    std::stringstream ss;
    ss << "This is the LevelSelect Screen. Press a button for a level";
    hud.setString(ss.str());
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
    buttonImage1.setPosition( 50.0f, 50.0f );
    buttonImage1.setTexture(button1);
    App.draw(buttonImage1);
    buttonImage2.setPosition( 150.0f, 50.0f );
    buttonImage2.setTexture(button2);
    App.draw(buttonImage2);
    buttonImage3.setPosition( 250.0f, 50.0f );
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

    App.display();
    return levelSelectOpen;
}
