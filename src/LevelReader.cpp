#include <LevelReader.h>
#include <fstream>
#include <iostream>

LevelState currentLevelState;

sf::Vector2f fastSpawnPt;
sf::Vector2f jumpSpawnPt;

LevelReader::LevelReader(){
	//fill the map array with zeros to represent 'empty' tiles
	/*for(int r = 0; r < 40; r++){
		for(int c = 0; c < 30; c++){
			this->map[r][c] = 0;
		}
	}*/
	for(int r = 0; r < 40; r++){
		std::vector<int> row;
		for(int c = 0; c < 30; c++){
			row.push_back(0);
		}
		this->map.push_back(row);
	}
}

void LevelReader::loadMap(const std::string& level){
	std::ifstream file;
	file.open("..\\levels\\" + level);
	if(!file.is_open()){
		std::cout << "Failed to load file";
		return;
	}
	std::string line;
	int xTile;
	int yTile;
	int tileID;

	//fill the map array with tileIDs that are specified in the text file
	while(file >> xTile >> yTile >> tileID){
		this->map[xTile][yTile] = tileID;
		if(tileID == 2){
			this->fastSpawnPt = sf::Vector2f(xTile, yTile);
		}
		if(tileID == 3){
			this->jumpSpawnPt = sf::Vector2f(xTile, yTile);
		}
	}
	file.close();
}

void LevelReader::setFastSpawnPt(sf::Vector2f pt){
	fastSpawnPt = pt;
}

void LevelReader::setJumpSpawnPt(sf::Vector2f pt){
	jumpSpawnPt = pt;
}

void LevelReader::setExitPt(sf::Vector2f pt){
	exitPt = pt;
}

LevelState LevelReader::createLevelState(){
	currentLevelState = LevelState(map, fastSpawnPt, jumpSpawnPt);
	return currentLevelState;
}