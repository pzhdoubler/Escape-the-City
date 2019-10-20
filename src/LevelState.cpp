#include <LevelState.h>

<<<<<<< HEAD
LevelState(int map[30][40], sf::Vector2f fastSpawnPt, sf::Vector2f jumpSpawnpt){
	this->tileSize = 20;
	this->map = map;
	this->fastSpawnPt = fastSpawnPt;
	this->jumpSpawnpt = jumpSpawnpt;
=======
LevelState(int map[40][30], sf::Vector2f fastSpawnPt, sf::Vector2f jumpSpawnPt){
	
>>>>>>> 9d42bb42d76dcefc419717397cc357caddf0bb27
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