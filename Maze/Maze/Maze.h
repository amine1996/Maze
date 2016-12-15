#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <assert.h>

class Maze
{
protected:
	int rowCount;
	int columnCount;
	clock_t generatingTime;

public:
	Maze(int pRow, int pColumn);
	int getRowCount() { return rowCount; }
	int getColumCount() { return columnCount; }

	void generateMaze();
	std::string toString();
};

