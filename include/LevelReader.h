#ifndef _LEVELREADER_H_
#define _LEVELREADER_H_

//LevelReader takes input from a text file and interprets it into arguments to pass
//to the LevelState constructor

class LevelReader{
	public:
		LevelReader();

		//reads a text file with the argument given of a path to map file
		void loadMap(const std::string&);

		sf::VertexArray vertices;

	private:

}

#endif //_LEVELREADER_H_