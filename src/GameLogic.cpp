#include <GameLogic.h>

#include <cmath>


bool GameLogic::init(LevelState level)
{
	this->level = level;
	//Read any important values from level
	//eg hazards, enemies, etc

	fast_man = new PlayerChar(true);
	jump_man = new PlayerChar(false);

	fast_man->setPos(level.getFastSpawnPt());
	jump_man->setPos(level.getJumpSpawnPt());

	fast_man->setVelocity(sf::Vector2f(0, 0));
	jump_man->setVelocity(sf::Vector2f(0, 0));
	//set starting positions and speeds
	//stored in level state

	//read in physics constants
	GRAVITY = 5;
	FAST_MAX_Y = 10;
	JUMP_MAX_Y = 7;

	return true;
}


bool GameLogic::update(float deltaMs)
{
	//update player state

	updatePlayerPosition(*fast_man, deltaMs);
	updatePlayerPosition(*high_man, deltaMs);

	//update other level objects
	return true;
}


std::vector<PlayerChar> GameLogic::getDrawables() //IMPLEMENT WITH GAMEELEMENTS NEXT
{

	std::vector<PlayerChar> drawables{ *fast, *high };

	//add all interactables

	return drawables;
}


void GameLogic::updatePlayerPosition(PlayerChar player, float deltaMs)
{
	float seconds = deltaMs / 1000.0;

	sf::Vector2f pos = player.getPos();
	sf::Vector2f vel = player.getVelocity();

	float new_vx = vel.x;
	float new_vy = vel.y;

	//apply gravity
	if (std::abs(int(vel.y)) > 0) 
		new_vy -= GRAVITY;

	//limit to max vert speed
	if (std::abs(int(new_vy)) > FAST_MAX_Y) {
		if (player.getType()) { //if fast char
			new_vy = FAST_MAX_Y;
		}
		else {
			if (std::abs(int(new_vy)) > JUMP_MAX_Y) {
				new_vy = JUMP_MAX_Y;
			}
		}
	}

	int tile_size = level.getTileSize();
	int player_height = player.getHeight();
	int player_width = player.getWidth();
	int level_layout[40][30] = level.getMatrix();

	float new_x = pos.x + (vel.x * seconds);
	float new_y = pos.y + (vel.y * seconds);

	//top left corner
	if (level_layout[int(new_x)/tile_size][int(new_y)/tile_size] == 1) {
		std::vector<float> shift = collisonCalculation(new_x, new_y);
		new_x = shift[0];
		new_y = shift[1];
		if (shift[2] == 0)
			new_vx = 0;
		else
			new_vy = 0;
	}
	//top right corner
	if (level_layout[(int(new_x) + player_width) / tile_size][int(new_y) / tile_size] == 1) {
		std::vector<float> shift = collisonCalculation(new_x + player_width, new_y);
		new_x = shift[0] - player_width;
		new_y = shift[1];
		if (shift[2] == 0)
			new_vx = 0;
		else
			new_vy = 0;
	}
	//bottom left corner
	if (level_layout[int(new_x) / tile_size][(int(new_y) - player_height) / tile_size] == 1) {
		std::vector<float> shift = collisonCalculation(new_x, new_y - player_height);
		new_x = shift[0];
		new_y = shift[1] + player_height;
		if (shift[2] == 0)
			new_vx = 0;
		else
			new_vy = 0;
	}
	//bottom right corner
	if (level_layout[(int(new_x) + player_width) / tile_size][(int(new_y) - player_height) / tile_size] == 1) {
		std::vector<float> shift = collisonCalculation(new_x + player_width, new_y - player_height);
		new_x = shift[0] - player_width;
		new_y = shift[1] + player_height;
		if (shift[2] == 0)
			new_vx = 0;
		else
			new_vy = 0;
	}

	sf::Vector2f new_pos = sf::Vector2f::Vector2(new_x, new_y);
	sf::Vector2f new_vel = sf::Vector2f::Vector2(new_vx, new_vy);

	player.setPos(new_pos);
	player.setVelocity(new_vel);

}


std::vector<float> GameLogic::collisionCalculation(float x, float y)
{
	int tile_size = level.getTileSize();

	int x_diff, y_diff;

	//get to closest x tile border
	if ((int(x) % tile_size) < (tile_size / 2))
		x_diff = -1 * (int(x) % tile_size);
	else
		x_diff = tile_size - (int(x) % tile_size);
	//get to closest y tile border
	if ((int(y) % tile_size) < (tile_size / 2))
		y_diff = -1 * (int(y) % tile_size);
	else
		y_diff = tile_size - (int(y) % tile_size);

	std::vector<float> to_return;
	//chooses shortest distance to fix to, defaults to horiz when equal
	if (std::abs(y_diff) < std::abs(x_diff)) {
		to_return.push_back(x);
		to_return.push_back(int(y) + y_diff);
		to_return.push_back(1);
	}
	else {
		to_return.push_back(int(x) + x_diff);
		to_return.push_back(y);
		to_return.push_back(0);
	}

	return to_return;
}