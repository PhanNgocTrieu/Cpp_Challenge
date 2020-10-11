//Given an array of integers, find the maximal absolute difference between any two of its adjacent elements.
//
//Example
//
//For inputArray = [2, 4, 1, 0], the output should be
//arrayMaximalAdjacentDifference(inputArray) = 3.

#include <iostream>
#include <vector>

int arrayMaximalAdjacentDifference(std::vector<int> inputArray) {
	int size = inputArray.size();
	int max = -9;
	int dems;
	for (int i = 1; i < size; i++)
	{
		if (inputArray[i] > inputArray[i-1])
		{
			dems = inputArray[i] - inputArray[i - 1];
		}
		else
		{
			dems = inputArray[i - 1] - inputArray[i];
		}

		if (dems > max)
		{
			max = dems;
		}
	}
	return max;
}

int main()
{
	std::vector<int> inputArray = { -1, 4, 10, 3, -2 };
	std::cout << arrayMaximalAdjacentDifference(inputArray);
	return 0;
}
