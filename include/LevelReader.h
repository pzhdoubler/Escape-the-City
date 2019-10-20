#ifndef _LEVELREADER_H_
#define _LEVELREADER_H_

//LevelReader takes input from a text file and interprets it into arguments to pass
//to the LevelState constructor

class LevelReader{
	public:
		LevelReader();

		//reads a text file with the argument given of a path to map file
		void loadMap(std::string& level);

		LevelState createLevelState();

		//makes array to give to LevelState of IDs that are collision points from the tile map
		

		void setFastSpawnPt(sf::Vector2f pt);
		void setJumpSpawnPt(sf::Vector2f pt);

		void setExitPt(sf::Vector2f pt);

	private:
		sf::Vector2f fastSpawnPt;
		sf::Vector2f jumpSpawnpt;

		sf::Vector2f exitPt;

		int map[40][30]; //stores values for each tile and their id, pass to LevelState

}

#endif //_LEVELREADER_H_