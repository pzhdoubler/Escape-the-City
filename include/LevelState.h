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

		//saves tags for anything that is a barrier for collision tags
		sf::VertexArray vertices;

		void draw();


	private:
		sf::Sprite mapTile; //full tile sheet
		sf::Sprite background; //sprite for the static background
		sf::View *viewPointer; //pointer to the GameLogic


}

#endif //_LEVELSTATE_H_