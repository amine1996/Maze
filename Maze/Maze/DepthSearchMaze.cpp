#include "DepthSearchMaze.h"
#include <iostream>

DepthSearchMaze::DepthSearchMaze(int pRow, int pColumn) : Maze(pRow,pColumn)
{
	initMaze();
}

void DepthSearchMaze::generateMaze()
{
	position pos = { 0,0 };
	std::vector<position> history;
	history.push_back(pos);

	while (history.size() > 0)
	{
		maze[pos.row][pos.column].visited = true;


		std::vector<direction> check;
		if (pos.column - 1 >= 0  && /*!maze[pos.row][pos.column-1].isWall &&*/ !maze[pos.row][pos.column-1].visited)
			check.push_back(LEFT);

		if (pos.column + 1 < column && /*!maze[pos.row][pos.column+1].isWall &&*/ !maze[pos.row][pos.column + 1].visited)
			check.push_back(RIGHT);

		if (pos.row - 1 >= 0 && /*!maze[pos.row-1][pos.column].isWall && */!maze[pos.row - 1][pos.column].visited)
			check.push_back(UP);

		if (pos.row + 1 < row &&/* !maze[pos.row+1][pos.column].isWall && */!maze[pos.row + 1][pos.column].visited)
			check.push_back(DOWN);

		if (check.size() > 0)
		{
			history.push_back(pos);

			const int size = check.size();
			int direction = check.at(rand() % size);

			if (direction == LEFT)
			{
				maze[pos.row][pos.column].leftIsWall = true;
				pos.column -= 1;
				maze[pos.row][pos.column].rightIsWall = true;
			}
			else if (direction == RIGHT)
			{
				maze[pos.row][pos.column].rightIsWall = true;
				pos.column += 1;
				maze[pos.row][pos.column].leftIsWall = true;
			}
			else if (direction == UP)
			{
				maze[pos.row][pos.column].upIsWall = true;
				pos.row -= 1;
				maze[pos.row][pos.column].downIsWall = true;
			}
			else if (direction == DOWN)
			{
				maze[pos.row][pos.column].downIsWall = true;
				pos.row += 1;
				maze[pos.row][pos.column].upIsWall = true;
			}

		}
		else
		{
			pos = history.at(history.size() - 1);
			history.pop_back();
		}
	}

	setWalls();

	maze[0][0].leftIsWall = false;
	maze[row - 1][column - 1].rightIsWall = false;
}

void DepthSearchMaze::initMaze()
{
	std::vector<cellData> vRow;
	std::vector<std::vector<cellData>> vCol;

	for (int i = 0; i < row; i++)
	{
		vRow.push_back(cellData());
	}

	for (int j = 0; j < column; j++)
	{
		vCol.push_back(vRow);
	}

	maze = vCol;
}

void DepthSearchMaze::setWalls()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (j - 1 >= 0 && maze[i][j].leftIsWall)
			{
				maze[i][j - 1].isWall = true;
			}

			if (j + 1 < column && maze[i][j].rightIsWall)
			{
				maze[i][j + 1].isWall = true;
			}

			if (i - 1 >= 0 && maze[i][j].upIsWall)
			{
				maze[i-1][j].isWall = true;
			}

			if (i + 1 < row && maze[i][j].downIsWall)
			{
				maze[i+1][j].isWall = true;
			}
				
		}
	}
}

std::string DepthSearchMaze::toString()
{
	std::string res = "";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (maze[i][j].isWall)
				res += WALL;
			else
				res += SPACE;
		}
		res += "\n";
	}
	return res;
}