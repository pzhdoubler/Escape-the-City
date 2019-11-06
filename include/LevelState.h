#ifndef _LEVELSTATE_H_
#define _LEVELSTATE_H_

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

//LevelState takes input from LevelReader and builds the level itself

class LevelState {
public:
	//Default constructor
	LevelState(){};

	LevelState(std::vector<std::vector<int>> map, sf::Vector2f fastSpawnPt, sf::Vector2f jumpSpawnPt, int tileSize, std::vector<sf::Vector2f> buttonPos, std::vector<sf::Vector2f> pressurePlatePos, std::vector<sf::Vector2f> doorPos, std::vector<sf::Vector2f> hazardPos, std::vector<sf::Vector2f> movPlatformPos);

	sf::Vector2f& getFastSpawnPt();

	sf::Vector2f& getJumpSpawnPt();

	int getTileSize();

	const std::vector<std::vector<int>>& getTileMap() const;

	const std::vector<sf::Vector2f>& getButtonPos() const;
	const std::vector<sf::Vector2f>& getPressurePlatePos() const;
	const std::vector<sf::Vector2f>& getDoorPos() const;
	const std::vector<sf::Vector2f>& getHazardPos() const;
	const std::vector<sf::Vector2f>& getMovPlatformPos() const;

	void printLevelState();

	//get method for array of values for collision detection

	void draw();

	const std::vector<std::vector<int>>& getCollisionMap() const;


private:
	sf::View* viewPointer; //pointer to the GameLogic

	sf::Vector2f fastSpawnPt;
	sf::Vector2f jumpSpawnPt;

	sf::Vector2f exitPt;

	int tileSize;

	std::vector<std::vector<int>> map; //stores values for each tile and their id

	std::vector<std::vector<int>> collisionMap; //stores values for collision tiles

	//vector of button positions
	std::vector<sf::Vector2f> buttonPos;

	//vector of hazard positions
	std::vector<sf::Vector2f> pressurePlatePos;

	//vector of toggle door positions
	std::vector<sf::Vector2f> doorPos;

	//vector of toggle spike positions
	std::vector<sf::Vector2f> hazardPos;

	//vector of moving platform positions
	std::vector<sf::Vector2f> movPlatformPos;
};

#endif //_LEVELSTATE_H_