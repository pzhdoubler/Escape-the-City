#ifndef _APPLAYER_H_
#define _APPLAYER_H_

#include <SFML/Graphics.hpp>
#include <string>
#include <LevelReader.h>
#include <LevelState.h>


class AppLayer 
{
	public:
		AppLayer() {};

		//displays a menu based on screen_pref variable (eg Main Menu, Pause, etc)
		//also receives user input and interprets results
		//returns true if a new level should be loaded and false otherwise
		bool display(sf::RenderWindow& mainWindow, int screen_pref);

		//loads the level
		LevelState loadLevel();

	private:
		LevelReader loader;

		std::string level_name;
		//various menu sprites

};

#endif // !_APPLAYER_H_