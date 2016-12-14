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
	std::vector<position> getNeighbors(position pPos);
	Cell getCell(position pPos) { return maze.at(pPos.row).at(pPos.column);/*[pPos.row][pPos.column]*/ }
	void setCell(position pPos, Cell pCell) { maze.at(pPos.row).at(pPos.column) = pCell;/*[pPos.row][pPos.column] = pCell*/ }

	bool inMaze(position pos);
	position getOpposedCellPosition(position centerCell, position neighborCell);


public:
	PrimMaze(int pRowCount, int pColumnCount);

	void generateMaze();
	std::string toString();

};

