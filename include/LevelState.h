#ifndef _LEVELSTATE_H_
#define _LEVELSTATE_H_

//LevelState takes input from LevelReader and builds the level itself

class LevelState{
	public:
		//Constructor
		//LevelReader interprets text files to pass into the LevelState constructor
		//Default constructor
		LevelState();

		//updates background tiles and static objects
		LevelState updateLevelState();


	private:
}

#endif //_LEVELSTATE_H_