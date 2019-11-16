#include <LevelState.h>
#include <cstdio>

LevelState::LevelState(std::vector<std::vector<int>> map, sf::Vector2f fastSpawnPt, sf::Vector2f jumpSpawnPt, sf::Vector2f exitPt, int tileSize, std::vector<sf::Vector2f>& buttonPos, std::vector<sf::Vector2f>& pressurePlatePos, std::vector<sf::Vector2f>& doorPos, std::vector<sf::Vector2f>& hazardPos, std::vector<sf::Vector2f>& movPlatformPos) {
	this->map = map;
	this->fastSpawnPt = fastSpawnPt;
	this->jumpSpawnPt = jumpSpawnPt;
	this->exitPt = exitPt;
	this->tileSize = tileSize;
	this->buttonPos = buttonPos;
	this->pressurePlatePos = pressurePlatePos;
	this->doorPos = doorPos;
	this->hazardPos = hazardPos;
	this->movPlatformPos = movPlatformPos;

	//sets all barriers to 1, all other tiles are set to 0 for collision detection
	this->collisionMap.resize(40);
	for(int r = 0; r < 40; r++){
		this->collisionMap[r].resize(30);
		for(int c = 0; c < 30; c++){
			if(this->map[r][c] != 1 ){
				this->collisionMap[r][c] = 0;
			}
			else{
				this->collisionMap[r][c] = 1;
			}
		}
	}
}

sf::Vector2f& LevelState::getFastSpawnPt(){
	return fastSpawnPt;
}

sf::Vector2f& LevelState::getJumpSpawnPt(){
	return jumpSpawnPt;
}

sf::Vector2f& LevelState::getExitPt() {
	return exitPt;
}

int LevelState::getTileSize(){
	return tileSize;
}

const std::vector<std::vector<int>>& LevelState::getTileMap() const {
	return map;
}

const std::vector<std::vector<int>>& LevelState::getCollisionMap() const{
	return collisionMap;
}

const std::vector<sf::Vector2f>& LevelState::getButtonPos() {
	return buttonPos;
}

const std::vector<sf::Vector2f>& LevelState::getPressurePlatePos() {
	return pressurePlatePos;
}
const std::vector<sf::Vector2f>& LevelState::getDoorPos() {
	return doorPos;
}
const std::vector<sf::Vector2f>& LevelState::getHazardPos() {
	return hazardPos;
}
const std::vector<sf::Vector2f>& LevelState::getMovPlatformPos() {
	return movPlatformPos;
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
