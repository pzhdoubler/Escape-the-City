#include <Barrier.h>

#include <utility>
#include <cmath>


const std::vector<int> Barrier::upVector{ 0, -1 };
const std::vector<int> Barrier::downVector{ 0, 1 };
const std::vector<int> Barrier::leftVector{ -1, 0 };
const std::vector<int> Barrier::rightVector{ 1, 0 };
const std::vector<int> Barrier::zeroVector{ 0, 0 };


bool Barrier::init(LevelState& level, int x_coord, int y_coord, int edgePoints)
{
	std::vector<std::vector<int>> tileMap = level.getTileMap();
	int tileSize = level.getTileSize();

	tileID = tileMap[x_coord][y_coord];

	position.push_back(x_coord*tileSize);
	position.push_back(y_coord*tileSize);

	if (edgePoints == -1)
		return false;

	int edgeSectionLength = tileSize / (edgePoints + 1);

	//Top edge
	if (y_coord > 0 && tileMap[x_coord][y_coord-1] != 1) 
	{
		int current_X = position[0];
		int current_Y = position[1];
		for (int i = 1; i <= (edgePoints + 2); i++) {
			if (i == edgePoints + 2)
				current_X = position[0] + tileSize;

			std::vector<int> point{ current_X, current_Y };
			std::vector<Barrier::UnitDirection> u_vector{ Down };
			collisionVectors[point] = u_vector;
			collisionPoints.push_back(point);

			current_X += edgeSectionLength;
		}
	}
	//Bottom edge
	if (y_coord < tileMap[0].size() && tileMap[x_coord][y_coord+1] != 1)
	{
		int current_X = position[0];
		int current_Y = position[1] + tileSize;
		for (int i = 1; i <= (edgePoints + 2); i++) {
			if (i == edgePoints + 2)
				current_X = position[0] + tileSize;

			std::vector<int> point{ current_X, current_Y };
			std::vector<Barrier::UnitDirection> u_vector{ Up };
			collisionVectors[point] = u_vector;
			collisionPoints.push_back(point);

			current_X += edgeSectionLength;
		}
	}

	//Need to check for duplicate key values since corners may be initialized
	std::map<std::vector<int>, std::vector<UnitDirection>>::iterator map_iter;

	//Left edge
	if (x_coord > 0 && tileMap[x_coord-1][y_coord] != 1)
	{
		int current_X = position[0];
		int current_Y = position[1];
		for (int i = 1; i <= (edgePoints + 2); i++) {
			if (i == edgePoints + 2)
				current_Y = position[1] + tileSize;
			std::vector<int> point{ current_X, current_Y };

			map_iter = collisionVectors.find(point);
			if (map_iter == collisionVectors.end()) {
				std::vector<Barrier::UnitDirection> u_vector{ Right };
				collisionVectors[point] = u_vector;
				collisionPoints.push_back(point);
			}
			else {
				collisionVectors[point].push_back(Right);
			}
			current_Y += edgeSectionLength;
		}
	}
	//Right edge
	if (x_coord < tileMap.size() && tileMap[x_coord+1][y_coord] != 1)
	{
		int current_X = position[0] + tileSize;
		int current_Y = position[1];
		for (int i = 1; i <= (edgePoints + 2); i++) {
			if (i == edgePoints + 2)
				current_Y = position[0] + tileSize;
			std::vector<int> point{ current_X, current_Y };

			map_iter = collisionVectors.find(point);
			if (map_iter == collisionVectors.end()) {
				std::vector<Barrier::UnitDirection> u_vector{ Left };
				collisionVectors[point] = u_vector;
				collisionPoints.push_back(point);
			}
			else {
				collisionVectors[point].push_back(Left);
			}
			current_Y += edgeSectionLength;
		}
	}

	return true;
}


const std::vector<std::vector<int>>& Barrier::getCollisionPoints() const
{
	return collisionPoints;
}


const std::vector<int>& Barrier::getClosestCollisionPoint(int x_pos, int y_pos) const
{
	int point_index = 0;
	int min_dist = std::abs(x_pos - collisionPoints[0][0]) - std::abs(y_pos - collisionPoints[0][1]);
	for (int i = 1; i < collisionPoints.size(); i++) {
		int this_dist = std::abs(x_pos - collisionPoints[i][0]) - std::abs(y_pos - collisionPoints[i][1]);
		if (this_dist < min_dist) {
			min_dist = this_dist;
			point_index = i;
		}
	}
	return collisionPoints[point_index];
}


const std::vector<Barrier::UnitDirection>& Barrier::getCollisionPointVectors(std::vector<int>& point)
{
	return collisionVectors[point];
}


const std::vector<int>& Barrier::getDirectionVector(Barrier::UnitDirection dir)
{
	switch (dir)
	{
		case Barrier::Up:
			return upVector;
		case Barrier::Down:
			return downVector;
		case Barrier::Left:
			return leftVector;
		case Barrier::Right:
			return rightVector;
		default:
			return zeroVector;
	}
}