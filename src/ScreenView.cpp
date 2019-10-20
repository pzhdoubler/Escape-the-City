//
// Created by 8luke on 10/9/2019.
//

#include "ScreenView.h"

ScreenView::ScreenView(LevelState level) {
    //I know for the first level we will want an instruction box in the upper left hand corner
    //we will want to initialize some sort of HUD like we did in Pong with fonts and texts to draw that show instructions
    //but we need to know what level we are on because we don't need text drawn on every level
    sf::Sprite levelOutline = init(level);
}

sf::Sprite ScreenView::init(LevelState level) {
    //iterate through a 2d array that has either a 0 or 1. If 0, progress. If 1, draw a 20x20 box.
    //Draw rectangles by making a new RectangleShape obj with setSize(20,20), setFillColor(white), setPosition(i,j).
    //Every iteration, increment j by 20 until you hit 800 (max width). Then increment i by 20 and restart loop until
    // you hit 600 (max height)
    sf::RectangleShape border;
    sf::RenderTexture textureCanvas;
    textureCanvas.create(800,600);
    int width = 40;
    int height = 30;
    textureCanvas.clear(sf::Color::White);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (level.getTileMap()[i][j] == 1) {
                border.setSize(sf::Vector2f(20,20));
                border.setFillColor(sf::Color::Black);
                border.setPosition(i*20, j*20);
                textureCanvas.draw(border);
            }
        }
    }

    const sf::Texture texture = textureCanvas.getTexture();
    sf::Sprite spriteCanvas(texture);
    return spriteCanvas;

}

void ScreenView::update(sf::RenderWindow &mainWindow, GameLogic &gameLogic) {

    mainWindow.clear(); //clear and replace with whatever color we want to use or maybe with background sprite?


    //the PlayerCharacter objects in the vector each have their own draw method so we can just call that and send in our
    //mainWindow reference
    mainWindow.draw(levelOutline);
    gameLogic.getDrawables().at(0).draw(mainWindow);
    gameLogic.getDrawables().at(1).draw(mainWindow);
}