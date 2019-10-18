#include <LogicView.h>

#include <cmath>


bool GameLogic::init(LevelState level)
{
	this->level = level;
	//Read any important values from level
	//eg hazards, enemies, etc

	fast = PlayerChar(true);
	high = PlayerChar(false);
	//set starting positions and speeds
	//stored in level state

	//read in physics constants
	GRAVITY = 5;

	return true;
}


bool GameLogic::update(float deltaMs)
{
	//update player state

	updatePlayerPosition(fast, "", deltaMs);
	updatePlayerPosition(high, "", deltaMs);

	//update other level objects
	return true;
}


std::vector<PlayerChar> GameLogic::getDrawables(); //IMPLEMENT WITH GAMEELEMENTS NEXT
{

	std::vector<PlayerChar> drawables{ fast, high };

	//add all interactables

	return drawables;
}


void GameLogic::updatePlayerPosition(PlayerChar player, String button, float deltaMs)
{
	float seconds = deltaMs / 1000.0;

	sf::Vector2f pos = player.getPos();
	sf::Vector2f vel = player.getVelocity();

	float new_vx = vel.x;
	float new_vy = vel.y;

	//apply gravity
	if (abs(vel.y) > 0.0) 
		new_vy -= GRAVITY;

	//limit to max vert speed
	if (abs(new_vy) > FAST_MAX_Y) {
		if (player.getType()) { //if fast char
			new_vy = FAST_MAX_Y;
		}
		else {
			if (abs(new_vy) > HIGH_MAX_Y) {
				new_vy = HIGH_MAX_Y;
			}
		}
	}

	float new_x = pos.x + (vel.x * seconds);
	float new_y = pos.y + (vel.y * seconds);

	sf::Vector2f new_pos = sf::Vector2f::Vector2(new_x, new_y);
	sf::Vector2f new_vel = sf::Vector2f::Vector2(new_vx, new_vy);

	player.setPos(new_pos);
	player.setVelocity(new_vel);

}