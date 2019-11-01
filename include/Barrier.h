#ifndef _BARRIER_H_
#define _BARRIER_H_

#include <vector>
#include <LevelState.h>

class Barrier 
{

	public:
		Barrier() {};

		//Initializes a barrier based on its position in LevelState
		//edgePoints is the number of edges to be placed on each barrier edge NOT COUNTING CORNERS
		//pass edgePoints = -1 for null barrier
		//WILL USE COLLISON MAP IN FUTURE
		bool init(LevelState &level, int x_coord, int y_coord, int edgePoints);

		enum UnitDirection
		{
			Up,
			Down,
			Left,
			Right
		};

		const std::vector<std::vector<int>>& getCollisionPoints() const;

		const std::vector<int>& getClosestCollisionPoint(int x_pos, int y_pos) const;

		const std::vector<UnitDirection>& getCollisionPointVectors(std::vector<int>& point);

		static const std::vector<int>& getDirectionVector(UnitDirection dir);

	private:

		int tileID;

		std::vector<int> position;

		std::vector<std::vector<int>> collisionPoints;

		std::vector<std::vector<UnitDirection>> collisionVectors;

		static const std::vector<int> upVector;
		static const std::vector<int> downVector;
		static const std::vector<int> leftVector;
		static const std::vector<int> rightVector;
		static const std::vector<int> zeroVector;


};

#endif // !_BARRIER_H_
