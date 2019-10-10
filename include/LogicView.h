#ifndef _LOGICVIEW_H_
#define _LOGICVIEW_H_


class LogicView
{
	public:
		//Default constructor
		LogicView() {};

		//Destructor that clears all internal fields
		~LogicView();

		//Initiallizes the gamestate based on the given LevelState description
		bool init(LevelState level);

		//Updates internal game state for the given time
		bool update(float deltaMs);

		//Returns a collection of all drawable objects in the game state to be updated
		GameElement[] getDrawables();

		//Recives button input and updates gamestate based on given time and button
		//filler type Key. Uses txt file?
		//void buttonPress(Key button, float deltaMs);


	private:

		//updates player's physics based on current postion and buttons press
		bool updatePlayerPosition(PlayerChar player, Key button, float deltaMs);

		//determines if the player is going to take damage or die based on current position
		bool updatePlayerState(PlayerChar player, float deltaMs);

		//updates any moving, non-player objects in the game
		bool updateObjects(float deltaMs);

		LevelState level;

		PlayerChar fast, jump;

		//Interactables[] hazards;

		//Interactables[] enemies;

		//Interactables[] items;

};

#endif // !_LOGICVIEW_H_