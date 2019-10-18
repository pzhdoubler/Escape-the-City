#ifndef _LOGICVIEW_H_
#define _LOGICVIEW_H_

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <vector>

#include <PlayerChar.h>
#include <GameElement.h>
#include <Interactable.h>


class LogicView
{
	public:
		//Default constructor
		LogicView() {};

		//Initiallizes the gamestate based on the given LevelState description
		bool init(LevelState level);

		//Updates internal game state for the given time
		bool update(float deltaMs);

		//Returns a collection of all drawable objects in the game state to be updated
		std::vector<PlayerChar> getDrawables();

		//Recives button input and updates gamestate based on given time and button
		//filler type Key. Uses txt file?
		//void buttonPress(Key button, float deltaMs);


	private:

		//updates player's physics based on current postion and buttons press
		void updatePlayerPosition(PlayerChar player, String button, float deltaMs);

		//determines if the player is going to take damage or die based on current position
		void updatePlayerState(PlayerChar player, float deltaMs);

		//updates any moving, non-player objects in the game
		void updateObjects(float deltaMs);

		LevelState level;

		PlayerChar fast, high;

		std::vector<Interactable> hazards;

		std::vector<Interactable> enemies;

		std::vector<Interactable> items;

		float GRAVITY;
		float FRICTION;
		float FAST_RUN, FAST_JUMP, FAST_MAX_X, FAST_MAX_Y;
		float HIGH_RUN, HIGH_JUMP, HIGH_MAX_X, HIGH_MAX_Y;

};

#endif // !_LOGICVIEW_H_