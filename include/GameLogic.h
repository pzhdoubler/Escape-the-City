#ifndef _GAMELOGIC_H_
#define _GAMELOGIC_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include <PlayerChar.h>
#include <GameElements.h>
#include <Interactables.h>
#include <LevelState.h>
#include <Controller.h>

class GameLogic
{
	public:
		//Default constructor
		GameLogic();

		//Initiallizes the gamestate based on the given LevelState description
		bool init(LevelState &level);

		//Updates internal game state for the given time
		bool update(float deltaMs);

		//Returns a collection of all drawable objects in the game state to be updated
		std::vector<GameElements*> getDrawables();

		//Recives button input and updates gamestate based on given time and button
		bool buttonPress(Controller::Controls button, float deltaMs);


	private:

		enum PointType
		{
			top_left,
			top_right,
			bot_left,
			bot_right,
			center
		};

		//determines the size of the hazard and returns true if horizontal and false for vertical
		bool determineObjectLength(int x_start, int y_start, int id, int& size);

		//updates player's physics based on current postion
		void updatePlayerPosition(PlayerChar& player, float deltaMs);

		//determines if the player is going to take damage or die based on current position
		void updatePlayerState(PlayerChar& player, float deltaMs);

		//updates any moving, non-player objects in the game
		void updateObjects(float deltaMs);

		//determines where a point should be after a collision. also communicates information about which axis was effected
		//last index is 0 for x-axis and 1 for y-axis
		std::vector<float> collisionCalculation(int tileXCoord, int tileYCoord, int prevTileX, int prevTileY, float posx, float posy, PointType corner);

		LevelState* level;

		std::shared_ptr<PlayerChar> fast_man;
		std::shared_ptr<PlayerChar> jump_man;

		std::vector<std::shared_ptr<Interactables>> buttons;

		std::vector<std::shared_ptr<Interactables>> pressure_plates;

		std::vector<std::shared_ptr<Interactables>> hazards;

		std::vector<std::shared_ptr<Interactables>> doors;

		std::vector<std::shared_ptr<Interactables>> enemies;

		std::vector<std::shared_ptr<Interactables>> items;

		int GRAVITY;
		int FRICTION;
		int FAST_RUN, FAST_HEIGHT, FAST_MAX_X, FAST_MAX_Y;
		int JUMP_RUN, JUMP_HEIGHT, JUMP_MAX_X, JUMP_MAX_Y;
		float FAST_VERT, JUMP_VERT, MIN_VERT;
		float FAST_AIR_MULT, JUMP_AIR_MULT;

};

#endif // !_GAMELOGIC_H_