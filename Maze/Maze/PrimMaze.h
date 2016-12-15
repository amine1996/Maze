#include "Maze.h"

class PrimMaze : public Maze
{
private:

	struct position
	{
		int row; 
		int column;
	};

	enum Cell
	{
		EMPTY,
		CORRIDOR,
		WALL
	};

	std::vector<std::vector<Cell>> maze;
	std::vector<position> toVisit;
	
	void initMaze();
	std::vector<position> getNeighborsPosition(position pPos);
	Cell getCellState(position pPos) { return maze[pPos.row][pPos.column]; }
	void setCellState(position pPos, Cell pCell) { maze[pPos.row][pPos.column] = pCell; }

	bool inMaze(position pos);
	position getOpposedCellPosition(position centerCell, position neighborCell);


public:
	PrimMaze(int pRowCount, int pColumnCount);

	void generateMaze();
	std::string toString();

};

