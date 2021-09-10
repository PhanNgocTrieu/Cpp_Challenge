//Given array of integers, remove each kth element from it.
//
//Example
//
//For inputArray = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] and k = 3, the output should be
//extractEachKth(inputArray, k) = [1, 2, 4, 5, 7, 8, 10].


#include <iostream>
#include <vector>

std::vector<int> extractEachKth(std::vector<int> &inputArray, int k) {
	int jum = k - 1;
	while (jum < inputArray.size())
	{
		std::cout << "We already removed this value: " << inputArray[jum] << "\n";
		for (int i = jum; i < inputArray.size() - 1; i++)
		{
			int j = i + 1;
			inputArray[i] = inputArray[j];
		}
		inputArray.pop_back();
		if (inputArray.size() - 1 == 0)
		{
			inputArray.pop_back();
			break;
		}
		jum = jum + (k - 1);
	}

	return inputArray;
}



int main()
{
	std::vector<int> inputArray = { 1,1,1,1,1,1,1 };
	for (auto i = inputArray.begin(); i != inputArray.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << "\n";
	int k = 1;
	std::vector<int> temp = extractEachKth(inputArray, k);
	for (auto i = temp.begin(); i != temp.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << "\n";
	return 0;
}
