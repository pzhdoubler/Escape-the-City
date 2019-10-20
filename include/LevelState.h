#ifndef _LEVELSTATE_H_
#define _LEVELSTATE_H_

#include <SFML/Graphics.hpp>
#include <map>

//LevelState takes input from LevelReader and builds the level itself

class LevelState{
	public:
		//Constructor
		//LevelReader interprets text files to pass into the LevelState constructor
		//Default constructor
		LevelState();

		LevelState(int map[30][40], sf::Vector2f fastSpawnPt, sf::Vector2f jumpSpawnpt);

		//updates background tiles and static objects
		LevelState updateLevelState(const sf::Time&);

		sf::Vector2f getFastSpawnPt();

		sf::Vector2f getJumpSpawnPt();

		//get method for array of values for collision detection

		void draw();


	private:
		sf::Sprite mapTile; //full tile sheet
		sf::Sprite background; //sprite for the static background
		sf::View *viewPointer; //pointer to the GameLogic

		sf::Vector2f fastSpawnPt;
		sf::Vector2f jumpSpawnpt;

		sf::Vector2f exitPt;

		int tileSize;

		int map[30][40]; //stores values for each tile and their id

		int collision[30][40]; //stores values for whether the tile is a collision (0 = default, 1 = collision)
}

#endif //_LEVELSTATE_H_