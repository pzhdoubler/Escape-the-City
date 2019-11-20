#include <LevelReader.h>
#include <fstream>
#include <iostream>
#include <sstream>

LevelReader::LevelReader(){
	//fill the map array with zeros to represent 'empty' tiles
	this->map.resize(40);
	for(int r = 0; r < 40; r++){
		this->map[r].resize(30);
		for(int c = 0; c < 30; c++){
			this->map[r][c] = 0;
		}
	}
}

void LevelReader::loadMap(const std::string& level){
	this->tileSize = 20;
	std::ifstream file;
	file.open("..\\levels\\" + level);
	if(!file.is_open()){
		std::cout << "Failed to load file";
	}

	std::vector<std::vector<int>> array;
	std::string line;
	std::string val;
	while(std::getline(file,line)){
		std::vector<int> v;
		std::stringstream lineStream(line);
		while(std::getline(lineStream, val, ',')){
			v.push_back(std::stoi(val));
		}
		array.push_back(v);
	}

	this->buttonPos.resize(6);
	this->pressurePlatePos.resize(6);
	this->doorPos.resize(6);
	this->hazardPos.resize(6);
	this->itemPos.resize(6);
	this->movPlatformPos.resize(6);
	
	for(int x = 0; x < array.size(); x++){
		for(int y = 0; y < array[x].size(); y++){
			if(array[x][y] == -1){
				this->map[y][x] = 0;
			}
			else if(array[x][y] == 0){
				this->map[y][x] = 1;
			}
			else if(array[x][y] == 1){
				this->jumpSpawnPt = sf::Vector2f(y*tileSize, x*tileSize);
				this->map[y][x] = 2;
			}
			else if(array[x][y] == 2){
				this->fastSpawnPt = sf::Vector2f(y*tileSize, x*tileSize);
				this->map[y][x] = 3;
			}
			else if(array[x][y] == 3){
				this->map[y][x] = 4;
				if (int(exitPt.x) == 0 && int(exitPt.y) == 0) {
					this->exitPt = sf::Vector2f(y*tileSize, x*tileSize);
				}
			}
			//button ids
			else if(array[x][y] >= 4 && array[x][y] <=9){
				this->map[y][x] = array[x][y] + 1;
				int index = array[x][y] - 4;
				if (int(buttonPos[index].x) == 0 && int(buttonPos[index].y) == 0) {
					this->buttonPos[index] = sf::Vector2f(y * tileSize, x * tileSize);
				}
			}
			//pressure plates
			else if(array[x][y] >= 10 && array[x][y] <=15){
				this->map[y][x] = array[x][y] + 1;
				int index = array[x][y] - 10;
				if (int(pressurePlatePos[index].x) == 0 && int(pressurePlatePos[index].y) == 0) {
					this->pressurePlatePos[index] = sf::Vector2f(y * tileSize, x * tileSize);
				}
			}
			//toggle doors
			else if(array[x][y] >= 16 && array[x][y] <=21){
				this->map[y][x] = array[x][y] + 1;
				int index = array[x][y] - 16;
				if (int(doorPos[index].x) == 0 && int(doorPos[index].y) == 0) {
					this->doorPos[index] = sf::Vector2f(y * tileSize, x * tileSize);
				}
			}
			//toggle hazards
			else if(array[x][y] >= 22 && array[x][y] <=27){
				this->map[y][x] = array[x][y] + 1;
				int index = array[x][y] - 22;
				if (int(hazardPos[index].x) == 0 && int(hazardPos[index].y) == 0) {
					this->hazardPos[index] = sf::Vector2f(y * tileSize, x * tileSize);
				}
			}
			//moving platforms
			else if(array[x][y] >= 28 && array[x][y] <=33){
				this->map[y][x] = array[x][y] + 1;
				int index = array[x][y] - 28;
				if (int(movPlatformPos[index].x) == 0 && int(movPlatformPos[index].y) == 0) {
					this->movPlatformPos[array[x][y] - 28] = sf::Vector2f(y * tileSize, x * tileSize);
				}
			}
			//items
			else if (array[x][y] >= 34 && array[x][y] <= 39) {
				this->map[y][x] = array[x][y] + 1;
				int index = array[x][y] - 34;
				if (int(itemPos[index].x) == 0 && int(itemPos[index].y) == 0) {
					this->itemPos[index] = sf::Vector2f(y * tileSize, x * tileSize);
				}
			}
			else{
				this->map[y][x] = 0;
			}
		}
	}
	file.close();

}

void LevelReader::setFastSpawnPt(sf::Vector2f pt){
	this->fastSpawnPt = pt;
}

void LevelReader::setJumpSpawnPt(sf::Vector2f pt){
	this->jumpSpawnPt = pt;
}

void LevelReader::setExitPt(sf::Vector2f pt){
	this->exitPt = pt;
}

LevelState LevelReader::createLevelState(){
	currentLevelState = LevelState(map, fastSpawnPt, jumpSpawnPt, exitPt, tileSize, buttonPos, pressurePlatePos, doorPos, hazardPos, itemPos, movPlatformPos);
	return currentLevelState;
}