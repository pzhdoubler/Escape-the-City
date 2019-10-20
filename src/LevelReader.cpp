#include <LevelReader.h>

LevelState currentLevelState;

sf::Vector2f fastSpawnPt;
sf::Vector2f jumpSpawnPt;

LevelReader(){

}

void LevelReader::loadMap(std::string& level){
	std::ifstream file;
	file.open(level);
	if(!file.is_open()){
		std::cout << "Failed to load file";
		return;
	}
	std::string line;
	while(std::getline(file, line)){
		//complete
	}
}

LevelState LevelReader:createLevelState(){

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
	return currentLevelState;
}