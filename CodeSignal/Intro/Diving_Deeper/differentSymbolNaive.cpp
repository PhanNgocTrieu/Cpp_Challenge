//Given a string, find the number of different characters in it.
//
//Example
//
//For s = "cabca", the output should be
//differentSymbolsNaive(s) = 3.
//
//There are 3 different characters a, band c

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int differentSymbolsNaive(std::string s) {
	std::vector<char> char_vec;
	int count = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (std::find(char_vec.begin(),char_vec.end(),s[i]) == char_vec.end())
		{
			char_vec.push_back(s[i]);
			count++;
		}
	}
	return count;
}

int main()
{
	std::string s = "cabca";
	std::cout << differentSymbolsNaive(s);
}
