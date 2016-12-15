#include "Maze.h"


Maze::Maze(int pRow, int pColumn)
{
	assert(pRow >= 1 && pColumn >= 1);

	rowCount = pRow;
	columnCount = pColumn;
}