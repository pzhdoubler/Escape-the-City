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

    void update(sf::RenderWindow& mainWindow, LogicView& logicView);

    //How will the debug folder work for this? I tried making a Debug folder and running cmake .. and it failed
    //Also, why won't sf work?


};

#endif //CSCI437_SCREENVIEW_H
