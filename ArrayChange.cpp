//You are given an array of integers.On each move you are 
//allowed to increase exactly one of its element by one.
//Find the minimal number of moves required to obtain a strictly increasing sequence from the input.
//Example
//For inputArray = [1, 1, 1], the output should be
//arrayChange(inputArray) = 3.

#include <iostream>
#include <vector>

int arrayChange(std::vector<int> inputArray) {
	int count = 0;
	int size = inputArray.size();

	for (int i = 1; i < size; i++)
	{
		while (inputArray[i] <= inputArray[i-1])
		{
			inputArray[i]++;
			count++;
		}
	}
	return count;
}

int main()
{
	std::vector<int> inputArray = { -1000, 0, -2, 0 };
	//std::cout << ++(inputArray[1]);
	std::cout << arrayChange(inputArray);
	return 0;
}
