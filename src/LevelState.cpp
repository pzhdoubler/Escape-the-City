#include <LevelState.h>

LevelState(int map[40][30], sf::Vector2f fastSpawnPt, sf::Vector2f jumpSpawnpt){
	this->tileSize = 20;
	this->map = map;
	this->fastSpawnPt = fastSpawnPt;
	this->jumpSpawnpt = jumpSpawnpt;
}

sf::Vector2f LevelState::getFastSpawnPt(){
	return fastSpawnPt;
}

sf::Vector2f LevelState::getJumpSpawnPt(){
	return jumpSpawnPt;
}

int LevelState:getTileSize(){
	return tileSize;
}

int[][] LevelState::getTileMap() {
	return map
}