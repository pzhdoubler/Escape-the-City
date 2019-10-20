//
// Created by 8luke on 10/9/2019.
//

#include "ScreenView.h"

ScreenView::ScreenView() {
    //I know for the first level we will want an instruction box in the upper left hand corner
    //we will want to initialize some sort of HUD like we did in Pong with fonts and texts to draw that show instructions
    //but we need to know what level we are on because we don't need text drawn on every level
}

void ScreenView::update(sf::RenderWindow &mainWindow, GameLogic &gameLogic) {

    mainWindow.clear(); //clear and replace with whatever color we want to use or maybe with background sprite?

    //goes into the drawables vector at jumpman or fastman's location and retrieves a rectangleShape obj to be drawn
    //hopefully the rectangleShapes should have their position, velocity, etc updated in the logic
//    mainWindow.draw(gameLogic.getDrawables().at(0).fast_man);
//    mainWindow.draw(gameLogic.getDrawables().at(1).jump_man);

    //the PlayerCharacter objects in the vector each have their own draw method so we can just call that and send in our
    //mainWindow reference
    gameLogic.getDrawables().at(0).draw(mainWindow);
    gameLogic.getDrawables().at(1).draw(mainWindow);
}