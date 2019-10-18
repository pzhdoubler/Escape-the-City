#ifndef _LEVELREADER_H_
#define _LEVELREADER_H_

//LevelReader takes input from a text file and interprets it into arguments to pass
//to the LevelState constructor

class LevelReader{
	public:
		LevelReader();

		//reads a text file with the argument given of a path to map file
		void loadMap(const std::string&);

		LevelState createLevelState();

		sf::VertexArray vertices;

		void setFastSpawnPt();
		void setJumpSpawnPt();

	private:
		LevelState currentLevelState;

		sf::Vector2f fastSpawnPt;
		sf::Vector2f jumpSpawnpt;
}

#endif //_LEVELREADER_H_