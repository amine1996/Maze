#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

class Maze
{
protected:
	int row;
	int column;


public:
	const static char WALL = '*';
	const static char SPACE = ' ';

	Maze(int pRow, int pColumn);
	int getRow() { return row; }
	int getColum() { return column; }

	void generateMaze();
	std::string toString();
};

