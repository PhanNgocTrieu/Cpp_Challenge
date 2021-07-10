//You are given an array of integers representing coordinates of obstacles situated on a straight line.
//
//Assume that you are jumping from the point with coordinate 0 to the right.You are allowed only to make jumps of the same length represented by some integer.
//
//Find the minimal length of the jump enough to avoid all the obstacles.
//
//Example
//
//For inputArray = [5, 3, 6, 7, 9], the output should be
//avoidObstacles(inputArray) = 4.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int avoidObstacles(std::vector<int> inputArray) {
	
	int step = 0;
	bool isExist = true;
	int max = *max_element(inputArray.begin(), inputArray.end());
	do
	{
		step = step + 1;
		for (int i = 0; i <= max; i = i + step)
		{
			if (find(inputArray.begin(), inputArray.end(), i) != inputArray.end())
			{
				isExist = true;
				break;
			}
			else
			{
				isExist = false;
			}
		}
	} while (isExist == true);
	
	if (isExist == false)
	{
		return step;
	}
}

int main()
{
	std::vector<int> inputArray = { 1, 4, 10, 6, 2 }; //return 4
	std::cout << avoidObstacles(inputArray) << std::endl;

	return 0;
}
