#include <LevelState.h>

LevelState(int map[30][40], sf::Vector2f fastSpawnPt, sf::Vector2f jumpSpawnpt){
	
}

sf::Vector2f LevelState::getFastSpawnPt(){
	return fastSpawnPt;
}

sf::Vector2f LevelState::getJumpSpawnPt(){
	return jumpSpawnpt;
}

int LevelState:getTileSize(){
	return tileSize;
}