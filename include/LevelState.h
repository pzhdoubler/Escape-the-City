#ifndef _LEVELSTATE_H_
#define _LEVELSTATE_H_

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

//LevelState takes input from LevelReader and builds the level itself

class LevelState {
public:
	//Constructor
	//LevelReader interprets text files to pass into the LevelState constructor
	//Default constructor
	LevelState();

	LevelState(std::vector<std::vector<int>> map, sf::Vector2f fastSpawnPt, sf::Vector2f jumpSpawnPt);

	sf::Vector2f getFastSpawnPt();

	sf::Vector2f getJumpSpawnPt();

	int getTileSize();

	std::vector<std::vector<int>> getTileMap();

	//get method for array of values for collision detection

	void draw();


private:
	sf::View* viewPointer; //pointer to the GameLogic

	sf::Vector2f fastSpawnPt;
	sf::Vector2f jumpSpawnPt;

	sf::Vector2f exitPt;

	int tileSize;

	std::vector<std::vector<int>> map; //stores values for each tile and their id

	//int collision[40][30]; //stores values for whether the tile is a collision (0 = default, 1 = collision)
};

#endif //_LEVELSTATE_H_