//
// Created by 8luke on 10/4/2019.
//

#ifndef CSCI437_SCREENVIEW_H
#define CSCI437_SCREENVIEW_H


#include <SFML/Graphics/RenderWindow.hpp>

class ScreenView {

private:

public:
    //constructor
    //the constructor will most likely initiate fonts for text we want to display as well as
    //maybe do the initial entire updating of the screen to load the level in so then we don't need to worry
    //about updating everything during the main loop, just things that need to be updated as described below
    ScreenView();

    //will get a levelState object from levelEditor
    //uses that info to draws where barriers are, saves the canvas as a private field, draws it once then doesn't need to update it anymore
    //probably in the constructor or maybe it's own init function called when this is created



    //ScreenView doesn't need direct references to the character's coordinates, we can just ask for those
    //from the logic which will hold character instances.
    //this update should get those coordinates and then draw the main window based on the new coordinates
    //will also need to draw enemies, barriers, items, other classes using the GameElements interface
    void update(sf::RenderWindow& mainWindow, LogicView& logicView);


    //is y'all's  namespace sf also not working?


};

#endif //CSCI437_SCREENVIEW_H
