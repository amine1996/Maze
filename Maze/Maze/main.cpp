#include "PrimMaze.h"
#include <iostream>
#include <time.h>
int main()
{
	srand(time(NULL));
	PrimMaze maze(100, 100);


	std::cout << maze.toString();
	system("pause");
	return 0;
}