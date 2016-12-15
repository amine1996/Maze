#include "PrimMaze.h"
#include <iostream>

PrimMaze::PrimMaze(int pRowCount, int pColumnCount) : Maze(pRowCount,pColumnCount)
{
	clock_t beginning = clock();
	initMaze();
	generateMaze();
	generatingTime = clock() - beginning;
}

void PrimMaze::initMaze()
{
	for (int i = 0; i < rowCount; i++)
	{
		std::vector<Cell> vecCol;
		for (int j = 0; j < columnCount; j++)
		{
			vecCol.push_back(Cell::EMPTY);
		}
		maze.push_back(vecCol);
	}

	position posRand = { rand() % rowCount, rand() % columnCount };

	setCellState(posRand,Cell::CORRIDOR);
	std::vector<position> neighbors = getNeighborsPosition(posRand);

	for each(position pos in neighbors)
	{
		if (inMaze(pos))
		{
			setCellState(pos, Cell::WALL);
			toVisit.push_back(position{ pos.row,pos.column });
		}
	}
}

void PrimMaze::generateMaze()
{
	while (toVisit.size() > 0)
	{
		int popRand = rand() % toVisit.size();
		position poppedPos = toVisit.at(popRand);
		std::iter_swap(toVisit.begin() + popRand, toVisit.end()-1);
		toVisit.pop_back();

		std::vector<position> neighbors = getNeighborsPosition(poppedPos);
		int nbCorridor = 0;
		position corridorPos;

		for each(position pos in neighbors)
		{
			if (inMaze(pos))
			{
				if (getCellState(pos) == Cell::CORRIDOR)
				{
					corridorPos = pos;
					nbCorridor++;
				}
			}
		}

		if (nbCorridor == 1)
		{
			if (inMaze(getOpposedCellPosition(poppedPos, corridorPos)))
			{
				if(getCellState(getOpposedCellPosition(poppedPos, corridorPos)) == Cell::EMPTY)
					setCellState(poppedPos, Cell::CORRIDOR);
			}
			for each(position pos in neighbors)
			{
				if (inMaze(pos))
				{
					if (getCellState(pos) == Cell::EMPTY)
					{
						setCellState(pos, Cell::WALL);
						toVisit.push_back(pos);
					}
				}
			}
		}
	}
}

bool PrimMaze::inMaze(position pos)
{
	return pos.row < rowCount && pos.column < columnCount && pos.row >=0 && pos.column >= 0;
}

PrimMaze::position PrimMaze::getOpposedCellPosition(position centerCell, position neighborCell)
{
	return position{ centerCell.row + (centerCell.row - neighborCell.row),centerCell.column + (centerCell.column - neighborCell.column) };
}


std::vector<PrimMaze::position> PrimMaze::getNeighborsPosition(position pPos)
{
	position pos = pPos;
	std::vector<position> neighbors;

	if (pos.row + 1 < rowCount)
		neighbors.push_back(position{ pos.row + 1,pos.column });
	if (pos.column + 1 < columnCount)
		neighbors.push_back(position{ pos.row,pos.column + 1 });
	if (pos.row - 1 >= 0)
		neighbors.push_back(position{ pos.row - 1,pos.column });
	if (pos.column - 1 >= 0)
		neighbors.push_back(position{ pos.row,pos.column - 1 });

	return neighbors;
}

std::string PrimMaze::toString()
{
	std::string res = "";
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < columnCount; j++)
		{
			switch (getCellState(position{ i,j }))
			{
				case Cell::WALL:
					res += (char)177;
					break;
				case Cell::CORRIDOR:
					res += ' ';
					break;
				default:
					res += (char)176;
					break;
			}
		}
		res += "\n";
	}

	res += "Took " + std::to_string(generatingTime) + "ms to generate.\n";
	return res;
}