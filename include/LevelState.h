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

		//updates background tiles and static objects
		LevelState updateLevelState(const sf::Time&);

		sf::Vector2f getFastSpawnPt();

		sf::Vector2f getJumpSpawnPt();

		void draw();


	private:
		sf::Sprite mapTile; //full tile sheet
		sf::Sprite background; //sprite for the static background
		sf::View *viewPointer; //pointer to the GameLogic

		sf::Vector2f fastSpawnPt;
		sf::Vector2f jumpSpawnpt;

		sf::Vector2f exitPt;


}

#endif //_LEVELSTATE_H_