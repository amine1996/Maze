#include "DepthSearchMaze.h"
#include <iostream>
#include <time.h>
int main()
{
	srand(time(NULL));

	DepthSearchMaze DSM = DepthSearchMaze(10, 10);
	DSM.generateMaze();

	std::cout << DSM.toString();

	system("pause");
	return 0;
}