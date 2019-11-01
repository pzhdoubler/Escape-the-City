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

	std::vector<std::vector<int>> tileMap = level.getTileMap();

	//possibly determine how many edge points barriers should have here
	
	//for (int i = 0; i < tileMap.size(); i++) {
	//	std::vector<Barrier> row;
	//	barrierMap.push_back(row);
	//	for (int j = 0; j < tileMap[0].size(); i++) {
	//		Barrier barrier;
	//		if (tileMap[i][j] == 1) {
	//			printf("init valid %d, %d\n", i, j);
	//			barrier.init(level, i, j, 1);
	//			printf("finished init %d, %d\n", i, j);
	//		}
	//		else {
	//			printf("init invalid %d, %d\n", i, j);
	//			barrier.init(level, i, j, -1);
	//			printf("finished init %d, %d\n", i, j);
	//		}
	//		barrierMap[i].push_back(barrier);
	//		printf("pushed\n");
	//	}
	//}

	//Read any important values from level
	//eg hazards, enemies, etc

	fast_man->setPos(level.getFastSpawnPt());
	jump_man->setPos(level.getJumpSpawnPt());

	sf::Vector2f grav_test_start(200, 200);
	fast_man->setPos(grav_test_start);

	sf::Vector2f zeros(0, 0);
	fast_man->setVelocity(zeros);
	jump_man->setVelocity(zeros);
	//set starting positions and speeds
	//stored in level state

	//read in physics constants
	GRAVITY = 1000;
	FRICTION = 500;

	FAST_MAX_X = 2500;
	FAST_MAX_Y = 2500;
	FAST_RUN = 1000;
	FAST_VERT = 500;

	JUMP_MAX_X = 1000;
	JUMP_MAX_Y = 2000;
	JUMP_RUN = 500;
	JUMP_VERT = 1000;

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


std::vector<GameElements*> GameLogic::getDrawables()
{
	std::vector<GameElements*> drawables;

	GameElements* fast_ptr = fast_man.get();
	GameElements* jump_ptr = jump_man.get();

	drawables.push_back(fast_ptr);
	drawables.push_back(jump_ptr);

	//add all interactables

	return drawables;
}


void GameLogic::buttonPress(Controller::Controls button, float deltaMs)
{
	float seconds = deltaMs;

	sf::Vector2f fast_vel = fast_man->getVelocity();
	sf::Vector2f jump_vel = jump_man->getVelocity();

	switch (button)
	{
		case Controller::FAST_LEFT:
			fast_vel.x -= FAST_RUN * seconds;
			break;
		case Controller::FAST_RIGHT:
			fast_vel.x += FAST_RUN * seconds;
			break;
		case Controller::FAST_JUMP:
			if (!fast_man->isInAir()) {
				fast_vel.y = (-1)*FAST_VERT;
				fast_man->setInAir(true);
			}
			break;
		case Controller::FAST_DOWN:
			break;
		case Controller::FAST_USE:
			break;
		case Controller::JUMP_LEFT:
			jump_vel.x -= JUMP_RUN * seconds;
			break;
		case Controller::JUMP_RIGHT:
			jump_vel.x += JUMP_RUN * seconds;
			break;
		case Controller::JUMP_JUMP:
			if (!jump_man->isInAir()) {
				jump_vel.y = (-1)*JUMP_VERT;
				jump_man->setInAir(true);
			}
			break;
		case Controller::JUMP_DOWN:
			break;
		case Controller::JUMP_USE:
			break;

		default:
			break;
	}

	fast_man->setVelocity(fast_vel);
	jump_man->setVelocity(jump_vel);

}


std::vector<int> GameLogic::getUnitVector(UnitDirection direction)
{
	std::vector<int> dir;
	switch (direction)
	{
		case Up:
			dir.push_back(0);
			dir.push_back(-1);
			return dir;
		case Down:
			dir.push_back(0);
			dir.push_back(1);
			return dir;
		case Left:
			dir.push_back(-1);
			dir.push_back(0);
			return dir;
		case Right:
			dir.push_back(1);
			dir.push_back(0);
			return dir;
	}
}


int GameLogic::dotProduct(int v1x, int v1y, int v2x, int v2y)
{
	return (v1x * v2x) + (v1y * v2x);
}


std::vector<float> GameLogic::collisionCalculation(float x, float y, UnitDirection dir)
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

	switch (dir) {
		case Up:
		case Down:
			to_return.push_back(x);
			to_return.push_back(int(y) + y_diff);
			return to_return;
		case Left:
		case Right:
			to_return.push_back(int(x) + x_diff);
			to_return.push_back(y);
			return to_return;
	}
}


std::vector<int> GameLogic::getClosestCollisionPoint(int tile_x, int tile_y, float pos_x, float pos_y)
{
	int tileSize = level->getTileSize();
	int halfTileSize = tileSize / 2;
	int tileXPos = tile_x * tileSize;
	int tileYPos = tile_y * tileSize;

	//top left corner
	std::vector<int> colPoint{ tileXPos, tileYPos };
	float min_dist = std::abs(float(tileXPos) - pos_x) + std::abs(float(tileYPos) - pos_y);
	//top edge
	if (std::abs(float(tileXPos + halfTileSize) - pos_x) + std::abs(float(tileYPos) - pos_y) < min_dist) {
		colPoint[0] = tileXPos + halfTileSize;
		colPoint[1] = tileYPos;
		min_dist = std::abs(float(tileXPos + halfTileSize) - pos_x) + std::abs(float(tileYPos) - pos_y);
	}
	//top right corner
	if (std::abs(float(tileXPos + tileSize) - pos_x) + std::abs(float(tileYPos) - pos_y) < min_dist) {
		colPoint[0] = tileXPos + tileSize;
		colPoint[1] = tileYPos;
		min_dist = std::abs(float(tileXPos + tileSize) - pos_x) + std::abs(float(tileYPos) - pos_y);
	}
	//right edge
	if (std::abs(float(tileXPos + tileSize) - pos_x) + std::abs(float(tileYPos + halfTileSize) - pos_y) < min_dist) {
		colPoint[0] = tileXPos + tileSize;
		colPoint[1] = tileYPos + halfTileSize;
		min_dist = std::abs(float(tileXPos + tileSize) - pos_x) + std::abs(float(tileYPos + halfTileSize) - pos_y);
	}
	//bot right corner
	if (std::abs(float(tileXPos + tileSize) - pos_x) + std::abs(float(tileYPos + tileSize) - pos_y) < min_dist) {
		colPoint[0] = tileXPos + tileSize;
		colPoint[1] = tileYPos + tileSize;
		min_dist = std::abs(float(tileXPos + tileSize) - pos_x) + std::abs(float(tileYPos + tileSize) - pos_y);
	}
	//bot edge
	if (std::abs(float(tileXPos + halfTileSize) - pos_x) + std::abs(float(tileYPos + tileSize) - pos_y) < min_dist) {
		colPoint[0] = tileXPos + halfTileSize;
		colPoint[1] = tileYPos + tileSize;
		min_dist = std::abs(float(tileXPos + halfTileSize) - pos_x) + std::abs(float(tileYPos + tileSize) - pos_y);
	}
	//bot left corner
	if (std::abs(float(tileXPos) - pos_x) + std::abs(float(tileYPos + tileSize) - pos_y) < min_dist) {
		colPoint[0] = tileXPos;
		colPoint[1] = tileYPos + tileSize;
		min_dist = std::abs(float(tileXPos) - pos_x) + std::abs(float(tileYPos + tileSize) - pos_y);
	}
	//left edge
	if (std::abs(float(tileXPos) - pos_x) + std::abs(float(tileYPos + halfTileSize) - pos_y) < min_dist) {
		colPoint[0] = tileXPos;
		colPoint[1] = tileYPos + halfTileSize;
		min_dist = std::abs(float(tileXPos) - pos_x) + std::abs(float(tileYPos + halfTileSize) - pos_y);
	}

	return colPoint;
}


std::vector<GameLogic::UnitDirection> GameLogic::getCollisionVectors(int point_x, int point_y)
{
	std::vector<std::vector<int>> tileMap = level->getTileMap();
	int tileSize = level->getTileSize();
	int halfTileSize = tileSize / 2;
	std::vector<UnitDirection> vectors;
	//corner
	if (point_x % tileSize == 0 && point_y % tileSize == 0) {
		int coord_x = point_x / tileSize;
		int coord_y = point_y / tileSize;
		int barrier_count = tileMap[coord_x][coord_y] + tileMap[coord_x - 1][coord_y] + tileMap[coord_x - 1][coord_y - 1] + tileMap[coord_x][coord_x - 1];
		switch (barrier_count) {
		case 1:
			if (tileMap[coord_x][coord_y] == 1) {
				vectors.push_back(Down);
				vectors.push_back(Right);
			}
			else if (tileMap[coord_x - 1][coord_y] == 1) {
				vectors.push_back(Down);
				vectors.push_back(Left);
			}
			else if (tileMap[coord_x - 1][coord_y - 1] == 1) {
				vectors.push_back(Up);
				vectors.push_back(Left);
			}
			else {
				vectors.push_back(Up);
				vectors.push_back(Right);
			}
		case 2:
			if (tileMap[coord_x][coord_y] == 1 && tileMap[coord_x - 1][coord_y] == 1) {
				vectors.push_back(Down);
			}
			else if (tileMap[coord_x - 1][coord_y] == 1 && tileMap[coord_x - 1][coord_y - 1] == 1) {
				vectors.push_back(Left);
			}
			else if (tileMap[coord_x - 1][coord_y - 1] == 1 && tileMap[coord_x][coord_y - 1] == 1) {
				vectors.push_back(Up);
			}
			else {
				vectors.push_back(Right);
			}
		case 3:
			if (tileMap[coord_x][coord_y] != 1) {
				vectors.push_back(Up);
				vectors.push_back(Left);
			}
			else if (tileMap[coord_x - 1][coord_y] != 1) {
				vectors.push_back(Up);
				vectors.push_back(Right);
			}
			else if (tileMap[coord_x - 1][coord_y - 1] != 1) {
				vectors.push_back(Down);
				vectors.push_back(Right);
			}
			else {
				vectors.push_back(Down);
				vectors.push_back(Left);
			}
		}
	}
	//vertical edge
	else if (point_x % tileSize == 0) {
		//barrier to right
		if (tileMap[point_x / tileSize][(point_y - halfTileSize) / tileSize] == 1)
			vectors.push_back(Left);
		else
			vectors.push_back(Right);
	}
	//horizontal edge
	else if (point_y % tileSize == 0) {
		//barrier on bottom
		if (tileMap[(point_x - halfTileSize) / tileSize][point_y / tileSize] == 1)
			vectors.push_back(Up);
		else
			vectors.push_back(Down);
	}

	return vectors;
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

	//apply friction on ground

	int tile_size = level->getTileSize();
	int player_height = player.getHeight();
	int player_width = player.getWidth();
	std::vector<std::vector<int>> level_layout = level->getTileMap();

	float deltaX = vel.x * seconds;
	float deltaY = vel.y * seconds;

	float new_x = pos.x + deltaX;
	float new_y = pos.y + deltaY;

	//bool checkCollision = true;

	std::vector<float> center{ new_x + (player_width / 2), new_y + (player_height / 2) };
	std::vector<float> top_left{ new_x , new_y };
	std::vector<float> top_right{ new_x + player_width, new_y };
	std::vector<float> bot_left{ new_x , new_y + player_height };
	std::vector<float> bot_right{ new_x + player_width, new_y + player_height };

	std::vector<std::vector<int>> possibleCollisionPoints;
	//check corners
	if (level_layout[int(top_left[0]) / tile_size][int(top_left[1]) / tile_size] == 1) {
		possibleCollisionPoints.push_back(getClosestCollisionPoint(int(top_left[0]) / tile_size, int(top_left[1]) / tile_size, center[0], center[1]));
	}
	if (level_layout[int(top_right[0]) / tile_size][int(top_right[1]) / tile_size] == 1) {
		possibleCollisionPoints.push_back(getClosestCollisionPoint(int(top_right[0]) / tile_size, int(top_right[1]) / tile_size, center[0], center[1]));
	}
	if (level_layout[int(bot_left[0]) / tile_size][int(bot_left[1]) / tile_size] == 1) {
		possibleCollisionPoints.push_back(getClosestCollisionPoint(int(bot_left[0]) / tile_size, int(bot_left[1]) / tile_size, center[0], center[1]));
	}
	if (level_layout[int(bot_right[0]) / tile_size][int(bot_right[1]) / tile_size] == 1) {
		possibleCollisionPoints.push_back(getClosestCollisionPoint(int(bot_left[0]) / tile_size, int(bot_left[1]) / tile_size, center[0], center[1]));
	}

	if (possibleCollisionPoints.size() > 0) {
		//choose closest of chosen points
		int collisionPointIndex = 0;
		int min_dist = std::abs(possibleCollisionPoints[0][0] - center[0]) + std::abs(possibleCollisionPoints[0][1] - center[0]);
		for (int i = 1; i < possibleCollisionPoints.size(); i++) {
			int this_dist = std::abs(possibleCollisionPoints[i][0] - center[0]) + std::abs(possibleCollisionPoints[i][1] - center[0]);
			if (this_dist < min_dist) {
				collisionPointIndex = i;
				min_dist = this_dist;
			}
		}

		std::vector<int> collisionPoint = possibleCollisionPoints[collisionPointIndex];
		if (player.getType()) {
			printf("col point: %d, %d\n", collisionPoint[0], collisionPoint[1]);
		}
		std::vector<UnitDirection> u_vectors = getCollisionVectors(collisionPoint[0], collisionPoint[1]);
		if (player.getType()) {
			printf("col vectors: ");
			for (int i = 0; i < u_vectors.size(); i++) {
				printf("%d ", u_vectors[i]);
			}
			printf("\n");
		}

		int d1_x, d1_y, d2_x, d2_y;
		//check dot products with all edges and adjust appropriately
		for (int i = 0; i < u_vectors.size(); i++) {
			std::vector<int> u_v = getUnitVector(u_vectors[i]);
			std::vector<float> shift;
			//top edge
			if (u_vectors[i] == Up || u_vectors[i] == Down) {
				d1_x = top_left[0] - collisionPoint[0];
				d1_y = top_left[1] - collisionPoint[1];
				d2_x = top_right[0] - collisionPoint[0];
				d2_y = top_right[1] - collisionPoint[1];
				if (dotProduct(d1_x, d1_y, u_v[0], u_v[1])*dotProduct(d2_x, d2_y, u_v[0], u_v[1]) < 0) {
					if (player.getType()) {
						printf("top edge\n");
					}
					shift = collisionCalculation(top_left[0], top_left[1], Down);
					new_y = shift[1];
					new_vy = 0;
				}
				//bottom edge
				d1_x = bot_left[0] - collisionPoint[0];
				d1_y = bot_left[1] - collisionPoint[1];
				d2_x = bot_right[0] - collisionPoint[0];
				d2_y = bot_right[1] - collisionPoint[1];
				if (dotProduct(d1_x, d1_y, u_v[0], u_v[1])*dotProduct(d2_x, d2_y, u_v[0], u_v[1]) < 0) {
					if (player.getType()) {
						printf("bottom edge\n");
					}
					shift = collisionCalculation(bot_left[0], bot_left[1], Up);
					new_y = shift[1] - player_height;
					new_vy = 0;
					player.setInAir(false);
				}
			}
			else {
				//left edge
				d1_x = top_left[0] - collisionPoint[0];
				d1_y = top_left[1] - collisionPoint[1];
				d2_x = bot_left[0] - collisionPoint[0];
				d2_y = bot_left[1] - collisionPoint[1];
				if (dotProduct(d1_x, d1_y, u_v[0], u_v[1])*dotProduct(d2_x, d2_y, u_v[0], u_v[1]) < 0) {
					if (player.getType()) {
						printf("left edge\n");
					}
					shift = collisionCalculation(top_left[0], top_left[1], Right);
					new_x = shift[0];
					new_vx = 0;
				}
				//right edge
				d1_x = bot_right[0] - collisionPoint[0];
				d1_y = bot_right[1] - collisionPoint[1];
				d2_x = top_right[0] - collisionPoint[0];
				d2_y = top_right[1] - collisionPoint[1];
				if (dotProduct(d1_x, d1_y, u_v[0], u_v[1])*dotProduct(d2_x, d2_y, u_v[0], u_v[1]) < 0) {
					if (player.getType()) {
						printf("right edge\n");
					}
					shift = collisionCalculation(top_right[0], top_right[1], Left);
					new_x = shift[0] - player_width;
					new_vx = 0;
				}
			}
		}
	}
	


	//while (checkCollision) 
	//{


	//}


	////top left corner
	//if (level_layout[int(new_x)/tile_size][int(new_y)/tile_size] == 1) {
	//	std::vector<float> shift = collisionCalculation(new_x, new_y);
	//	new_x = shift[0];
	//	new_y = shift[1];
	//	if (shift[2] == 0) {
	//		new_vx = 0;
	//	}
	//	else {
	//		new_vy = 0;
	//		player.setInAir(false);
	//	}
	//}
	////top right corner
	//if (level_layout[(int(new_x) + player_width) / tile_size][int(new_y) / tile_size] == 1) {
	//	std::vector<float> shift = collisionCalculation(new_x + player_width, new_y);
	//	new_x = shift[0] - player_width;
	//	new_y = shift[1];
	//	if (shift[2] == 0) {
	//		new_vx = 0;
	//	}
	//	else {
	//		new_vy = 0;
	//		player.setInAir(false);
	//	}
	//}
	////bottom left corner
	//if (level_layout[int(new_x) / tile_size][(int(new_y) + player_height) / tile_size] == 1) {
	//	std::vector<float> shift = collisionCalculation(new_x, new_y + player_height);
	//	new_x = shift[0];
	//	new_y = shift[1] - player_height;
	//	if (shift[2] == 0) {
	//		new_vx = 0;
	//	}
	//	else {
	//		new_vy = 0;
	//		player.setInAir(false);
	//	}
	//}
	////bottom right corner
	//if (level_layout[(int(new_x) + player_width) / tile_size][(int(new_y) + player_height) / tile_size] == 1) {
	//	std::vector<float> shift = collisionCalculation(new_x + player_width, new_y + player_height);
	//	new_x = shift[0] - player_width;
	//	new_y = shift[1] - player_height;
	//	if (shift[2] == 0) {
	//		new_vx = 0;
	//	}
	//	else {
	//		new_vy = 0;
	//		player.setInAir(false);
	//	}
	//}

	sf::Vector2f new_pos = sf::Vector2f(new_x, new_y);
	sf::Vector2f new_vel = sf::Vector2f(new_vx, new_vy);

	player.setPos(new_pos);
	player.setVelocity(new_vel);

}


