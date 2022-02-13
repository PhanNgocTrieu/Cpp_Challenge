//Given an array of strings, return another array containing all of its longest strings.
//
//Example
//
//For inputArray = ["aba", "aa", "ad", "vcd", "aba"], the output should be
//allLongestStrings(inputArray) = ["aba", "vcd", "aba"].
//Input / Output
//
//[execution time limit] 0.5 seconds(cpp)
//
//[input] array.string inputArray
//
//A non - empty array.
//
//Guaranteed constraints :
//1 ≤ inputArray.length ≤ 10,
//1 ≤ inputArray[i].length ≤ 10.
//
//[output] array.string
//
//Array of the longest strings, stored in the same order as in the inputArray.

#include <iostream>
#include <vector>
#include <string>


std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray) {
	std::vector<std::string> outputArray;
	int longest_length = inputArray[0].length();
	for (int i = 1; i < inputArray.size(); i++)
	{
		if (inputArray[i].length() > longest_length)
		{
			longest_length = inputArray[i].length();
		}
	}

	for (int j = 0; j < inputArray.size(); j++)
	{
		if (inputArray[j].length() == longest_length)
		{
			outputArray.push_back(inputArray[j]);
		}
	}

	return outputArray;
}

int main()
{
	std::vector<std::string> inputArray = { "aba", "aa", "ad", "vcd", "aba" };

	std::vector<std::string> temp = allLongestStrings(inputArray);

	for (int i = 0; i < temp.size(); i++)
	{
		std::cout << temp[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
