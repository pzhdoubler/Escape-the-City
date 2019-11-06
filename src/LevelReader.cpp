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
	//file.open("..\\levels\\" + level);
	file.open("..\\levels\\level_tutorial.csv");
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
				this->exitPt = sf::Vector2f(y*tileSize, x*tileSize);
				this->map[y][x] = 4;
			}
			//button ids
			else if(array[x][y] >= 4 or array[x][y] <=9){
				this->buttonPos.resize(6);
				this->buttonPos[array[x][y] - 4] = sf::Vector2f(y*tileSize, x*tileSize);
				this->map[y][x] = array[x][y] + 1;
			}
			//pressure plates
			else if(array[x][y] >= 10 or array[x][y] <=15){
				this->pressurePlatePos.resize(6);
				this->pressurePlatePos[array[x][y] - 10] = sf::Vector2f(y*tileSize, x*tileSize);
				this->map[y][x] = array[x][y] + 1;
			}
			//toggle doors
			else if(array[x][y] >= 16 or array[x][y] <=21){
				this->doorPos.resize(6);
				this->doorPos[array[x][y] - 16] = sf::Vector2f(y*tileSize, x*tileSize);
				this->map[y][x] = array[x][y] + 1;
			}
			//toggle hazards
			else if(array[x][y] >= 22 or array[x][y] <=27){
				this->hazardPos.resize(6);
				this->hazardPos[array[x][y] - 22] = sf::Vector2f(y*tileSize, x*tileSize);
				this->map[y][x] = array[x][y] + 1;
			}
			//moving platforms
			else if(array[x][y] >= 28 or array[x][y] <=33){
				this->movPlatformPos.resize(6);
				this->movPlatformPos[array[x][y] - 28] = sf::Vector2f(y*tileSize, x*tileSize);
				this->map[y][x] = array[x][y] + 1;
			}
			else{
				this->map[y][x] = 0;
			}
		}
	}
	file.close();

	//this->fastSpawnPt = sf::Vector2f(1*20, 28*20);
	//this->jumpSpawnPt = sf::Vector2f(2*20, 28*20);

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
	currentLevelState = LevelState(map, fastSpawnPt, jumpSpawnPt, tileSize, buttonPos, pressurePlatePos, doorPos, hazardPos, movPlatformPos);
	return currentLevelState;
}