#include <GameLogic.h>

#include <cmath>


GameLogic::GameLogic()
{
	fast_man = std::make_shared<PlayerChar>(true);
	jump_man = std::make_shared<PlayerChar>(false);
}


bool GameLogic::init(LevelState &level)
{
	this->level = &level;
	//Read any important values from level
	//eg hazards, enemies, etc

	fast_man->setPos(level.getFastSpawnPt());
	jump_man->setPos(level.getJumpSpawnPt());

	//sf::Vector2f grav_test_start(200, 200);
	//fast_man->setPos(grav_test_start);

	sf::Vector2f zeros(0, 0);
	fast_man->setVelocity(zeros);
	jump_man->setVelocity(zeros);
	//set starting positions and speeds
	//stored in level state

	//read in physics constants
	GRAVITY = 1000;
	FAST_MAX_Y = 2500;
	JUMP_MAX_Y = 2000;

	return true;
}


bool GameLogic::update(float deltaMs)
{
	//level->printLevelState();

	//update player state

	updatePlayerPosition(*fast_man, deltaMs);
	updatePlayerPosition(*jump_man, deltaMs);

	//update other level objects
	return true;
}


std::vector<GameElements*> GameLogic::getDrawables() //IMPLEMENT WITH GAMEELEMENTS NEXT
{
	std::vector<GameElements*> drawables;

	GameElements* fast_ptr = fast_man.get();
	GameElements* jump_ptr = jump_man.get();

	drawables.push_back(fast_ptr);
	drawables.push_back(jump_ptr);

	//add all interactables

	return drawables;
}


std::vector<float> GameLogic::collisionCalculation(float x, float y)
{
	int tile_size = level->getTileSize();

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


void GameLogic::updatePlayerPosition(PlayerChar& player, float deltaMs)
{
	float seconds = deltaMs;

	sf::Vector2f pos = player.getPos();
	sf::Vector2f vel = player.getVelocity();

	float new_vx = vel.x;
	float new_vy = vel.y;

	//apply gravity
	new_vy += GRAVITY * seconds;

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

	int tile_size = level->getTileSize();
	int player_height = player.getHeight();
	int player_width = player.getWidth();
	std::vector<std::vector<int>> level_layout = level->getTileMap();

	float deltaX = vel.x * seconds;
	float deltaY = vel.y * seconds;

	float new_x = pos.x + deltaX;
	float new_y = pos.y + deltaY;

	//top left corner
	if (level_layout[int(new_x)/tile_size][int(new_y)/tile_size] == 1) {
		std::vector<float> shift = collisionCalculation(new_x, new_y);
		new_x = shift[0];
		new_y = shift[1];
		if (shift[2] == 0)
			new_vx = 0;
		else
			new_vy = 0;
	}
	//top right corner
	if (level_layout[(int(new_x) + player_width) / tile_size][int(new_y) / tile_size] == 1) {
		std::vector<float> shift = collisionCalculation(new_x + player_width, new_y);
		new_x = shift[0] - player_width;
		new_y = shift[1];
		if (shift[2] == 0)
			new_vx = 0;
		else
			new_vy = 0;
	}
	//bottom left corner
	if (level_layout[int(new_x) / tile_size][(int(new_y) + player_height) / tile_size] == 1) {
		std::vector<float> shift = collisionCalculation(new_x, new_y + player_height);
		new_x = shift[0];
		new_y = shift[1] - player_height;
		if (shift[2] == 0)
			new_vx = 0;
		else
			new_vy = 0;
	}
	//bottom right corner
	if (level_layout[(int(new_x) + player_width) / tile_size][(int(new_y) + player_height) / tile_size] == 1) {
		std::vector<float> shift = collisionCalculation(new_x + player_width, new_y + player_height);
		new_x = shift[0] - player_width;
		new_y = shift[1] - player_height;
		if (shift[2] == 0)
			new_vx = 0;
		else
			new_vy = 0;
	}

	sf::Vector2f new_pos = sf::Vector2f(new_x, new_y);
	sf::Vector2f new_vel = sf::Vector2f(new_vx, new_vy);

	player.setPos(new_pos);
	player.setVelocity(new_vel);

}


