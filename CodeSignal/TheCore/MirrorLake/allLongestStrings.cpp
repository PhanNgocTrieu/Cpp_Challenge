//Given an array of strings, return another array containing all of its longest strings.
//
//Example
//
//For inputArray = ["aba", "aa", "ad", "vcd", "aba"], the output should be
//allLongestStrings(inputArray) = ["aba", "vcd", "aba"].

#include <iostream>
#include <vector>

using namespace std;

void Print(vector<string> inputArray)
{
	for (string s : inputArray)
	{
		std::cout << s << " ";
	}
	std::cout << "\n";
}

vector<string> allLongestStrings(vector<string> inputArray) {

	vector<string> list{};
	int max_len = inputArray[0].length();
	for (string str : inputArray)
	{
		if (str.length() > max_len)
		{
			max_len = str.length();
			list = {};
			list.push_back(str);
		}
		else
		{
			if (str.length() == max_len)
			{
				list.push_back(str);
			}
		}
	}
	Print(list);
	return list;
}


int main()
{
	vector<string> inputArray{ "aba", "aa", "ad", "vcd", "aba" };
	vector<string> inputArray_2{ "abc",
		"eeee",
		"abcd",
		"dcd" };
	
	allLongestStrings(inputArray);
	allLongestStrings(inputArray_2);
	return 0;
}