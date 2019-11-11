//
// Created by 8luke on 10/4/2019.
//

#ifndef CSCI437_SCREENVIEW_H
#define CSCI437_SCREENVIEW_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "GameLogic.h"
#include "LevelState.h"



class ScreenView {

private:
    sf::Texture levelOutline;

	sf::Texture background;


public:
	//default constructor
	ScreenView() {};
    //constructor
    //the constructor will most likely initiate fonts for text we want to display as well as
    //maybe do the initial entire updating of the screen to load the level in so then we don't need to worry
    //about updating everything during the main loop, just things that need to be updated as described below
    //ScreenView();

    //this guy will be called by constructor, and do the iteration of an array. Save it as a sprite object that can be
    //called by the update first before any other drawing takes place
    void init(LevelState &level);



    //ScreenView doesn't need direct references to the character's coordinates, we can just ask for those
    //from the logic which will hold character instances.
    //this update should get those coordinates and then draw the main window based on the new coordinates
    //will also need to draw enemies, barriers, items, other classes using the GameElements interface
    void update(sf::RenderWindow& mainWindow, GameLogic& gameLogic);




};

#endif //CSCI437_SCREENVIEW_H
