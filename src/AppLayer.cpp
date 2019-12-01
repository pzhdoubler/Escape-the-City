//
// Created by 8luke on 10/25/2019.
//

#include "AppLayer.h"
#include <iostream>
#include <tinyxml2.h>


AppLayer::AppLayer() {

    //load font
    font.loadFromFile("..\\resources\\XPED Italic.TTF");
    hud.setFont(font);

    //set menu background
    static sf::Texture mainbg;
    mainbg.loadFromFile("..\\resources\\menuBackground.png");
    mainbackground = mainbg;

    //set level select background
    static sf::Texture levelbg;
    levelbg.loadFromFile("..\\resources\\levelSelectBackground2.jpg");
    levelbackground = levelbg;

}

bool AppLayer::mainMenu(sf::RenderWindow &App, bool &paused, Controller &controller, GameLogic &logic) {

    //set background color and string
    App.clear(sf::Color(0,0,0));
    //load background image

    sf::Sprite mainbg(mainbackground);
    App.draw(mainbg);
    hud.setCharacterSize(characterSize);
    hud.setPosition(mainStringXPos,mainStringYPos);
    hud.setString(mainMenuString);
    App.draw(hud);

    //draw optionButton
    sf::Texture optionButton;
    sf::Sprite optionButtonImage;
    if (!optionButton.loadFromFile( "..\\resources\\optionsButton.png"))
        std::cout << "Can't find the option image" << std::endl;
    optionButtonImage.setPosition(optionMenuButtonXPos, optionMenuButtonYPos);
    optionButtonImage.setTexture(optionButton);
    App.draw(optionButtonImage);

    //draw levelSelectButton
    sf::Texture levelSelectButton;
    sf::Sprite levelSelectButtonImage;
    if (!levelSelectButton.loadFromFile( "..\\resources\\levelButton.png"))
        std::cout << "Can't find the level image" << std::endl;
    levelSelectButtonImage.setPosition(levelSelectMenuButtonXPos, levelSelectMenuButtonYPos);
    levelSelectButtonImage.setTexture(levelSelectButton);
    App.draw(levelSelectButtonImage);

    //draw playButton
    sf::Texture playButton;
    sf::Sprite playButtonImage;
    if (!playButton.loadFromFile( "..\\resources\\playButton.png"))
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
                optionMenu(App, paused);
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

bool AppLayer::optionMenu(sf::RenderWindow &App, bool &paused) {

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

    //draw new text when a valid button is clicked
    sf::Texture bindButton;
    sf::Sprite bindButtonImage;
    if (!bindButton.loadFromFile("..\\resources\\keybindButton.png"))
        std::cout << "Can't find the keyBinding image" << std::endl;
    bindButtonImage.setPosition(optionMenuRebindButtonXPos, optionMenuRebindButtonYPos);
    bindButtonImage.setTexture(bindButton);
    App.draw(bindButtonImage);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mouseLocation = sf::Mouse::getPosition(App);
        sf::Vector2f mouseLocF(static_cast<float>(mouseLocation.x), static_cast<float>(mouseLocation.y));
        if (bindButtonImage.getGlobalBounds().contains(mouseLocF)) {
            printf("press the button you want to change\n");
            App.clear(sf::Color(optionMenuR, optionMenuG, optionMenuB));
            hud.setString(keyBindString);
            App.draw(hud);
            App.draw(backButtonImage);
            App.display();
            while (keyBinding(App, backButtonImage, paused)) {

            }

        }
    }


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

bool AppLayer::keyBinding(sf::RenderWindow &App, sf::Sprite backButtonImage, bool &paused) {
    //here we want to open the config file
    //read in values from file, currently correspond to default keys in design doc
    tinyxml2::XMLDocument config;
    tinyxml2::XMLError result = config.LoadFile("..\\config\\controls.xml");
    if (result != tinyxml2::XML_SUCCESS)
        return false;

    tinyxml2::XMLElement* fast = config.FirstChildElement("fastman");
    tinyxml2::XMLElement* jump = config.FirstChildElement("jumpman");


    bool fastButtons = false;
    bool jumpButtons = false;

    sf::Event event;


    while (App.pollEvent(event))
    {
        //if you press a key
        if (event.type == sf::Event::KeyPressed) {
            sf::Keyboard::Key keyboardKey = event.key.code;

            //get a corresponding number for your key
            //std::string keyBinding = fromKtoS(keyboardKey);
            int keyBinding = keyboardKey;
            //std::cout << "keyBinding: " << keyBinding << std::endl;


            //run through the XML bindings and add to a vector
            for (tinyxml2::XMLElement* key = fast->FirstChildElement(); key != NULL; key = key->NextSiblingElement()) {
                std::string strbinding =  key->GetText();
                int binding = std::stoi(strbinding);
                bindVectFast.push_back(binding);
                //std::cout << "binding: " << binding << std::endl;
            }

            //check and see if your key is in there
            //which would mean it is a fast man binding
            for (int s : bindVectFast) {
                if (keyBinding == s) {
                    fastButtons = true;
                    App.clear(sf::Color(optionMenuR, optionMenuG, optionMenuB));
                    hud.setString(keyBindChangeStr);
                    App.draw(hud);
                    App.draw(backButtonImage);
                    App.display();
                }

            }

            //if it was not in the fast man buttons, we need to check jump man buttons
            if (!fastButtons) {
                for (tinyxml2::XMLElement* key = jump->FirstChildElement(); key != NULL; key = key->NextSiblingElement()) {
                    std::string strbinding =  key->GetText();
                    int binding = std::stoi(strbinding);
                    bindVectJump.push_back(binding);
                    //std::cout << "binding: " << binding << std::endl;
                }
                //check and see if your key is in there
                //which would mean it is a jump man binding
                for (int s : bindVectJump) {
                    if (keyBinding == s) {
                        jumpButtons = true;
                        App.clear(sf::Color(optionMenuR, optionMenuG, optionMenuB));
                        hud.setString(keyBindChangeStr);
                        App.draw(hud);
                        App.draw(backButtonImage);
                        App.display();
                    }
                }
            }

            //we want to save previous binds from when we get either a fast or jump button hit because
            //keyBinding gets overwritten when we press the new key that doesn't correspond to something
            //in the XML file

            if (fastButtons || jumpButtons) {
                previousBinds.push_back(keyBinding);
            }


            //if we end up getting a hit for either fast of jump buttons, that means we should change it
            //now the user should input a new key and that should be the value of keyBindings
            //this key should not correspond to a fastButton or jumpButton so we go here to detect a new key
            //being pressed that we don't recognize
            if (!fastButtons && !jumpButtons) {
                std::cout << "curr keyBinding is: " << keyBinding << std::endl;
                int prevBind = previousBinds.at(previousBinds.size()-1);
                std::cout << "prev keyBinding is: " << prevBind << std::endl;


                //first search through the fast elements
                for (tinyxml2::XMLElement* key = fast->FirstChildElement(); key != NULL; key = key->NextSiblingElement()) {

                    //if we see an element that is equal to the previous binding we have a match
                    if (std::stoi(key->GetText()) == prevBind) {
                        //now we need to write keyBinding in the place of key->GetText
                        key->SetText(keyBinding);
                        App.clear(sf::Color(optionMenuR, optionMenuG, optionMenuB));
                        hud.setString(keyBindSuccStr);
                        App.draw(hud);
                        App.draw(backButtonImage);
                        App.display();
                    }
                }

                //then we search through jump elements
                for (tinyxml2::XMLElement* key = jump->FirstChildElement(); key != NULL; key = key->NextSiblingElement()) {

                    //if we see an element that is equal to the previous binding we have a match
                    if (std::stoi(key->GetText()) == prevBind) {

                        //now we need to write keyBinding in the place of key->GetText
                        key->SetText(keyBinding);
                        App.clear(sf::Color(optionMenuR, optionMenuG, optionMenuB));
                        hud.setString(keyBindSuccStr);
                        App.draw(hud);
                        App.draw(backButtonImage);
                        App.display();
                    }
                }
                config.SaveFile("..\\config\\controls.xml");
            }
        }

        //close out of the application
        if (event.type == sf::Event::Closed) {
            //break out of option menu loop
            optionMenuOpen = false;
            //break out of app layer loop
            isPlaying = true;
            //break out of game loop
            paused = true;
            App.close();
            //break out of keybinding loop
            return false;
        }

        //if back button is pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mouseLocation = sf::Mouse::getPosition(App);
            sf::Vector2f mouseLocF(static_cast<float>(mouseLocation.x), static_cast<float>(mouseLocation.y));
            if (backButtonImage.getGlobalBounds().contains(mouseLocF)) {
                printf("Going back to Option Menu...\n");
                return false;
            }
        }

    }

    return true;
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
    App.clear(sf::Color(0,0,0));
    sf::Sprite levelbg(levelbackground);
    App.draw(levelbg);
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
    sf::Texture button4;
    sf::Sprite buttonImage4;
    sf::Texture button5;
    sf::Sprite buttonImage5;
    sf::Texture button6;
    sf::Sprite buttonImage6;
    sf::Texture button7;
    sf::Sprite buttonImage7;
    sf::Texture button8;
    sf::Sprite buttonImage8;
    sf::Texture button9;
    sf::Sprite buttonImage9;
    sf::Texture button10;
    sf::Sprite buttonImage10;
    sf::Texture button11;
    sf::Sprite buttonImage11;
    sf::Texture button12;
    sf::Sprite buttonImage12;

    if (!button1.loadFromFile( "..\\resources\\level1Button.png"))
        std::cout << "Can't find the image" << std::endl;
    if (!button2.loadFromFile( "..\\resources\\level2Button.png"))
        std::cout << "Can't find the image" << std::endl;
    if (!button3.loadFromFile( "..\\resources\\level3Button.png"))
        std::cout << "Can't find the image" << std::endl;
    if (!button4.loadFromFile( "..\\resources\\level4Button.png"))
        std::cout << "Can't find the image" << std::endl;

    if (!button5.loadFromFile( "..\\resources\\level5Button.png"))
        std::cout << "Can't find the image" << std::endl;
    if (!button6.loadFromFile( "..\\resources\\level6Button.png"))
        std::cout << "Can't find the image" << std::endl;
    if (!button7.loadFromFile( "..\\resources\\level7Button.png"))
        std::cout << "Can't find the image" << std::endl;
    if (!button8.loadFromFile( "..\\resources\\level8Button.png"))
        std::cout << "Can't find the image" << std::endl;

    if (!button9.loadFromFile( "..\\resources\\level9Button.png"))
        std::cout << "Can't find the image" << std::endl;
    if (!button10.loadFromFile( "..\\resources\\level10Button.png"))
        std::cout << "Can't find the image" << std::endl;
    if (!button11.loadFromFile( "..\\resources\\level11Button.png"))
        std::cout << "Can't find the image" << std::endl;
    if (!button12.loadFromFile( "..\\resources\\level12Button.png"))
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
    buttonImage4.setPosition(button4LevelSelectXPos,button4LevelSelectYPos);
    buttonImage4.setTexture(button4);
    App.draw(buttonImage4);

    buttonImage5.setPosition(button5LevelSelectXPos, button5LevelSelectYPos);
    buttonImage5.setTexture(button5);
    App.draw(buttonImage5);
    buttonImage6.setPosition(button6LevelSelectXPos,button6LevelSelectYPos);
    buttonImage6.setTexture(button6);
    App.draw(buttonImage6);
    buttonImage7.setPosition(button7LevelSelectXPos,button7LevelSelectYPos);
    buttonImage7.setTexture(button7);
    App.draw(buttonImage7);
    buttonImage8.setPosition(button8LevelSelectXPos,button8LevelSelectYPos);
    buttonImage8.setTexture(button8);
    App.draw(buttonImage8);

    buttonImage9.setPosition(button9LevelSelectXPos, button9LevelSelectYPos);
    buttonImage9.setTexture(button9);
    App.draw(buttonImage9);
    buttonImage10.setPosition(button10LevelSelectXPos,button10LevelSelectYPos);
    buttonImage10.setTexture(button10);
    App.draw(buttonImage10);
    buttonImage11.setPosition(button11LevelSelectXPos,button11LevelSelectYPos);
    buttonImage11.setTexture(button11);
    App.draw(buttonImage11);
    buttonImage12.setPosition(button12LevelSelectXPos,button12LevelSelectYPos);
    buttonImage12.setTexture(button12);
    App.draw(buttonImage12);

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
            loader.loadMap("zack_level_1.csv");
            level = loader.createLevelState();
            printf("Going to level 1...\n");
            return levelSelectOpen;
        }
        if (buttonImage2.getGlobalBounds().contains(mouseLocF)) {
            printf("button clicked!\n");
			levelSelectOpen = false;
			isPlaying = true;
			loader.loadMap("zack_level_2.csv");
			level = loader.createLevelState();
			printf("Going to level 3...\n");
			return levelSelectOpen;
        }
        if (buttonImage3.getGlobalBounds().contains(mouseLocF)) {
			printf("button clicked!\n");
			levelSelectOpen = false;
			isPlaying = true;
			loader.loadMap("zack_level_3.csv");
			level = loader.createLevelState();
			printf("Going to level 3...\n");
			return levelSelectOpen;
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

//std::string AppLayer::fromKtoS(const sf::Keyboard::Key& k){
//    std::string ret;
//    switch(k){
//
//        case sf::Keyboard::A :
//
//            ret="0";
//            break;
//        case sf::Keyboard::B :
//
//            ret="1";
//            break;
//        case sf::Keyboard::C :
//
//            ret="2";
//            break;
//        case sf::Keyboard::D :
//
//            ret="3";
//            break;
//        case sf::Keyboard::E :
//
//            ret="4";
//            break;
//        case sf::Keyboard::F :
//
//            ret="5";
//            break;
//        case sf::Keyboard::G :
//
//            ret="6";
//            break;
//        case sf::Keyboard::H :
//
//            ret="7";
//            break;
//        case sf::Keyboard::I :
//
//            ret="8";
//            break;
//        case sf::Keyboard::J :
//
//            ret="9";
//            break;
//        case sf::Keyboard::K :
//
//            ret="10";
//            break;
//        case sf::Keyboard::L :
//
//            ret="11";
//            break;
//        case sf::Keyboard::M :
//
//            ret="12";
//            break;
//        case sf::Keyboard::N :
//
//            ret="13";
//            break;
//        case sf::Keyboard::O :
//
//            ret="14";
//            break;
//        case sf::Keyboard::P :
//
//            ret="15";
//            break;
//        case sf::Keyboard::Q :
//
//            ret="16";
//            break;
//        case sf::Keyboard::R :
//
//            ret="17";
//            break;
//        case sf::Keyboard::S :
//
//            ret="18";
//            break;
//        case sf::Keyboard::T :
//
//            ret="19";
//            break;
//        case sf::Keyboard::U :
//
//            ret="20";
//            break;
//        case sf::Keyboard::V :
//
//            ret="21";
//            break;
//        case sf::Keyboard::W :
//
//            ret="22";
//            break;
//        case sf::Keyboard::X :
//
//            ret="23";
//            break;
//        case sf::Keyboard::Y :
//
//            ret="24";
//            break;
//        case sf::Keyboard::Z :
//
//            ret="25";
//            break;
//        case sf::Keyboard::Num0 :
//
//            ret="26";
//            break;
//        case sf::Keyboard::Num1 :
//
//            ret="27";
//            break;
//        case sf::Keyboard::Num2 :
//
//            ret="28";
//            break;
//        case sf::Keyboard::Num3 :
//
//            ret="29";
//            break;
//        case sf::Keyboard::Num4 :
//
//            ret="30";
//            break;
//        case sf::Keyboard::Num5 :
//
//            ret="31";
//            break;
//        case sf::Keyboard::Num6 :
//
//            ret="32";
//            break;
//        case sf::Keyboard::Num7 :
//
//            ret="33";
//            break;
//        case sf::Keyboard::Num8 :
//
//            ret="34";
//            break;
//        case sf::Keyboard::Num9 :
//
//            ret="35";
//            break;
//        case sf::Keyboard::Escape :
//
//            ret="36";
//            break;
//        case sf::Keyboard::LControl :
//
//            ret="37";
//            break;
//        case sf::Keyboard::LShift :
//
//            ret="38";
//            break;
//        case sf::Keyboard::LAlt :
//
//            ret="39";
//            break;
//        case sf::Keyboard::LSystem :
//
//            ret="40";
//            break;
//        case sf::Keyboard::RControl :
//
//            ret="41";
//            break;
//        case sf::Keyboard::RShift :
//
//            ret="42";
//            break;
//        case sf::Keyboard::RAlt :
//
//            ret="43";
//            break;
//        case sf::Keyboard::RSystem :
//
//            ret="44";
//            break;
//        case sf::Keyboard::Menu :
//
//            ret="45";
//            break;
//        case sf::Keyboard::LBracket :
//
//            ret="46";
//            break;
//        case sf::Keyboard::RBracket :
//
//            ret="47";
//            break;
//        case sf::Keyboard::SemiColon :
//
//            ret="48";
//            break;
//        case sf::Keyboard::Comma :
//
//            ret="49";
//            break;
//        case sf::Keyboard::Period :
//
//            ret="50";
//            break;
//        case sf::Keyboard::Quote :
//
//            ret="51";
//            break;
//        case sf::Keyboard::Slash :
//
//            ret="52";
//            break;
//        case sf::Keyboard::BackSlash :
//
//            ret="53";
//            break;
//        case sf::Keyboard::Tilde :
//
//            ret="54";
//            break;
//        case sf::Keyboard::Equal :
//
//            ret="55";
//            break;
//        case sf::Keyboard::Dash :
//
//            ret="56";
//            break;
//        case sf::Keyboard::Space :
//
//            ret="57";
//            break;
//        case sf::Keyboard::Return :
//
//            ret="58";
//            break;
//        case sf::Keyboard::BackSpace :
//
//            ret="59";
//            break;
//        case sf::Keyboard::Tab :
//
//            ret="60";
//            break;
//        case sf::Keyboard::PageUp :
//
//            ret="61";
//            break;
//        case sf::Keyboard::PageDown :
//
//            ret="62";
//            break;
//        case sf::Keyboard::End :
//
//            ret="63";
//            break;
//        case sf::Keyboard::Home :
//
//            ret="64";
//            break;
//        case sf::Keyboard::Insert :
//
//            ret="65";
//            break;
//        case sf::Keyboard::Delete :
//
//            ret="66";
//            break;
//        case sf::Keyboard::Add :
//
//            ret="67";
//            break;
//        case sf::Keyboard::Subtract :
//
//            ret="68";
//            break;
//        case sf::Keyboard::Multiply :
//
//            ret="69";
//            break;
//        case sf::Keyboard::Divide :
//
//            ret="70";
//            break;
//        case sf::Keyboard::Left :
//
//            ret="71";
//            break;
//        case sf::Keyboard::Right :
//
//            ret="73";
//            break;
//        case sf::Keyboard::Up :
//
//            ret="74";
//            break;
//        case sf::Keyboard::Down :
//
//            ret="75";
//            break;
//        case sf::Keyboard::Numpad0 :
//
//            ret="76";
//            break;
//        case sf::Keyboard::Numpad1 :
//
//            ret="77";
//            break;
//        case sf::Keyboard::Numpad2 :
//
//            ret="78";
//            break;
//        case sf::Keyboard::Numpad3 :
//
//            ret="79";
//            break;
//        case sf::Keyboard::Numpad4 :
//
//            ret="80";
//            break;
//        case sf::Keyboard::Numpad5 :
//
//            ret="81";
//            break;
//        case sf::Keyboard::Numpad6 :
//
//            ret="82";
//            break;
//        case sf::Keyboard::Numpad7 :
//
//            ret="83";
//            break;
//        case sf::Keyboard::Numpad8 :
//
//            ret="84";
//            break;
//        case sf::Keyboard::Numpad9 :
//
//            ret="85";
//            break;
//        case sf::Keyboard::F1 :
//
//            ret="86";
//            break;
//        case sf::Keyboard::F2 :
//
//            ret="87";
//            break;
//        case sf::Keyboard::F3 :
//
//            ret="88";
//            break;
//        case sf::Keyboard::F4 :
//
//            ret="89";
//            break;
//        case sf::Keyboard::F5 :
//
//            ret="90";
//            break;
//        case sf::Keyboard::F6 :
//
//            ret="91";
//            break;
//        case sf::Keyboard::F7 :
//
//            ret="92";
//            break;
//        case sf::Keyboard::F8 :
//
//            ret="93";
//            break;
//        case sf::Keyboard::F9 :
//
//            ret="94";
//            break;
//        case sf::Keyboard::F10 :
//
//            ret="95";
//            break;
//        case sf::Keyboard::F11 :
//
//            ret="96";
//            break;
//        case sf::Keyboard::F12 :
//
//            ret="97";
//            break;
//        case sf::Keyboard::F13 :
//
//            ret="98";
//            break;
//        case sf::Keyboard::F14 :
//
//            ret="99";
//            break;
//        case sf::Keyboard::F15 :
//
//            ret="100";
//            break;
//        case sf::Keyboard::Pause :
//
//            ret="101";
//            break;
//        case sf::Keyboard::KeyCount :
//
//            ret="102";
//            break;
//
//
//        default:
//            ret="Unknow";
//            break;
//    }
//    return ret;

//  }