//
// Created by 8luke on 10/4/2019.
//

#ifndef CSCI437_SCREENVIEW_H
#define CSCI437_SCREENVIEW_H



class ScreenView {

private:

public:
    //constructor
    ScreenView();

    //the controller will be reading in input? Or does screenView need a keyboardInput function like in pong?


    //ScreenView doesn't need direct references to the character's coordinates, we can just ask for those
    //from the logic which will hold character instances.
    //this update should get those coordinates and then draw the main window based on the new coordinates
    //will also need to draw enemies, barriers, items, other classes using the GameElements interface
    void update(sf::RenderWindow& mainWindow, LogicView& logicView);


    //is y'all's  namespace sf also not working?


};

#endif //CSCI437_SCREENVIEW_H
