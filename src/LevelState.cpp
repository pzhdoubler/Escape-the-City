#include <LevelState.h>

LevelState::LevelState(std::vector<std::vector<int>> map, sf::Vector2f fastSpawnPt, sf::Vector2f jumpSpawnpt){
	this->tileSize = 20;
	this->map = map;
	this->fastSpawnPt = fastSpawnPt;
	this->jumpSpawnPt = jumpSpawnPt;
}

sf::Vector2f LevelState::getFastSpawnPt(){
	return fastSpawnPt;
}

sf::Vector2f LevelState::getJumpSpawnPt(){
	return jumpSpawnPt;
}

int LevelState::getTileSize(){
	return tileSize;
}

std::vector<std::vector<int>> LevelState::getTileMap() {
	return map;
}