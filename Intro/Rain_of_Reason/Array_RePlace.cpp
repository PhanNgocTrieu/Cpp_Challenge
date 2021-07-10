//Given an array of integers, replace all the occurrences of elemToReplace with substitutionElem.
//Example
//For inputArray = [1, 2, 1], elemToReplace = 1, and substitutionElem = 3, the output should be
//arrayReplace(inputArray, elemToReplace, substitutionElem) = [3, 2, 3].


#include <iostream>
#include <vector>

std::vector<int> arrayReplace(std::vector<int> inputArray, int elemToReplace, int substitutionElem) {
	std::vector<int> temp;
	int len = inputArray.size();
	for (int i = 0; i < len; i++)
	{
		if (inputArray[i] == elemToReplace)
		{
			temp.push_back(substitutionElem);
		}
		else
		{
			temp.push_back(inputArray[i]);
		}
	}
	return temp;
}

int main()
{
	std::vector<int> inputArray = { 1 ,2 ,1 };
	int elemReplace = 1;
	int substitutionElem = 3;
	std::vector<int> temp = arrayReplace(inputArray, elemReplace, substitutionElem);
	int size = temp.size();
	for (int i = 0; i < size; i++)
	{
		std::cout << temp[i] << " ";
	}

	return 0;
}
