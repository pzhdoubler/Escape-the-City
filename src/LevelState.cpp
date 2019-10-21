#include <LevelState.h>
#include <cstdio>

LevelState::LevelState(std::vector<std::vector<int>> map, sf::Vector2f fastSpawnPt, sf::Vector2f jumpSpawnPt){
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

const std::vector<std::vector<int>>& LevelState::getTileMap() const {
	return map;
}

void LevelState::printLevelState() {
	printf("tileSize: %d\n", tileSize);
	printf("fastSpawn: { %f, %f }\n", fastSpawnPt.x, fastSpawnPt.y);
	printf("jumpSpawn: { %f, %f }\n", jumpSpawnPt.x, jumpSpawnPt.y);
	printf("map: \n");
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}