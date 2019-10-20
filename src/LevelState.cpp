#include <LevelState.h>

LevelState(int map[40][30], sf::Vector2f fastSpawnPt, sf::Vector2f jumpSpawnPt){
	
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