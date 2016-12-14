#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

class Maze
{
protected:
	int rowCount;
	int columnCount;


public:
	Maze(int pRow, int pColumn);
	int getRowCount() { return rowCount; }
	int getColumCount() { return columnCount; }

	void generateMaze();
	std::string toString();
};

