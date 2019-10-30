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

bool AppLayer::mainMenu(sf::RenderWindow &App) {


    App.clear(sf::Color(0,0,255));

    std::stringstream ss;
    ss << "This is the Main Menu";
    hud.setString(ss.str());
    App.draw(hud);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        isPlaying = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
        printf("Going to Option Menu...\n");
        optionMenuOpen = true;
        while (optionMenuOpen) {
            sf::Event event;
            while (App.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
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
    ss << "This is the Option Screen";
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
    ss << "This is the LevelSelect Screen";
    hud.setString(ss.str());
    App.draw(hud);

    sf::Texture button;
    sf::Sprite buttonImage;
    if (!button.loadFromFile( "..\\resources\\button_template.png"))
        std::cout << "Can't find the image" << std::endl;
    buttonImage.setPosition( 50.0f, 50.0f );

    buttonImage.setTexture( button );
    App.draw(buttonImage);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mouseLocation = sf::Mouse::getPosition(App);
        sf::Vector2f mouseLocF(static_cast<float>(mouseLocation.x), static_cast<float>(mouseLocation.y));

        if (buttonImage.getGlobalBounds().contains(mouseLocF)) {
            printf("button clicked!\n");
            printf("Going back to Main Menu...\n");
            levelSelectOpen = false;
        }
    }

    App.display();
}
