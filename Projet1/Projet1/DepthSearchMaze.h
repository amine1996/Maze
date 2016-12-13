#include "Maze.h"

class DepthSearchMaze : public Maze
{
private:

	enum direction
	{
		LEFT,
		RIGHT,
		UP,
		DOWN
	};

	struct position
	{
		int row; 
		int column;
	};

	struct cellData
	{
		bool isWall = false;
		bool leftIsWall = false;
		bool rightIsWall = false;
		bool upIsWall = false;
		bool downIsWall = false;
		bool visited = false;
	};

	std::vector<std::vector<cellData>> maze;
	void initMaze();
	void setWalls();


public:
	DepthSearchMaze(int pRow, int pColumn);

	void generateMaze();
	std::string toString();

};

