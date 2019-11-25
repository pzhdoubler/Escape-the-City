//
// Created by 8luke on 10/9/2019.
//

#include "ScreenView.h"
#include <vector>

//ScreenView::ScreenView() {
//    //I know for the first level we will want an instruction box in the upper left hand corner
//    //we will want to initialize some sort of HUD like we did in Pong with fonts and texts to draw that show instructions
//    //but we need to know what level we are on because we don't need text drawn on every level
//
//}

void ScreenView::init(LevelState &level, ResourceManager& manager) {
    //iterate through a 2d array that has either a 0 or 1. If 0, progress. If 1, draw a 20x20 box.
    //Draw rectangles by making a new RectangleShape obj with setSize(20,20), setFillColor(white), setPosition(i,j).
    //Every iteration, increment j by 20 until you hit 800 (max width). Then increment i by 20 and restart loop until
    // you hit 600 (max height)
    sf::RenderTexture textureCanvas;
    textureCanvas.create(800,600);
    int width = 40;
    int height = 30;
    textureCanvas.clear(sf::Color(0,0,0,0));
	//background
	static sf::Texture bg;
	bg.loadFromFile("..\\resources\\citybackground.png"); //Do in resource manager
	background = bg;
	//barrier tiles
	sf::Vector2i size(level.getTileSize(), level.getTileSize());
	sf::Vector2i coords = manager.getSpriteCoords(ResourceManager::Sprites::BARRIER);
	sf::Vector2i spriteCoords(coords.x, coords.y);
	sf::IntRect spritePos(spriteCoords, size);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (level.getTileMap()[i][j] == 1) {
				sf::Sprite border(manager.getSpriteSheet(), spritePos);
				border.setPosition(i * level.getTileSize(), 580 - j * level.getTileSize());
				textureCanvas.draw(border);
				//printf("[ %d, %d ]\n", i, j);
            }
        }
    }

    static sf::Texture texture = textureCanvas.getTexture();
	levelOutline = texture;
}

void ScreenView::update(sf::RenderWindow &mainWindow, GameLogic &gameLogic) {

    mainWindow.clear(); //clear and replace with whatever color we want to use or maybe with background sprite?

    //the PlayerCharacter objects in the vector each have their own draw method so we can just call that and send in our
    //mainWindow reference
	sf::Sprite bg(background);
	mainWindow.draw(bg);
	sf::Sprite level(levelOutline);
    mainWindow.draw(level);
	std::vector<GameElements*> drawables = gameLogic.getDrawables();

	for (int i = 0; i < drawables.size(); i++) {
		drawables.at(i)->draw(mainWindow);
	}
	//drawables.at(0)->draw(mainWindow);
    //sdrawables.at(1)->draw(mainWindow);
}