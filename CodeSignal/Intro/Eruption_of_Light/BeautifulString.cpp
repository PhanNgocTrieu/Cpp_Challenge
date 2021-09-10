//A string is said to be beautiful 
//if each letter in the string appears at most as many times as the previous letter in the alphabet within the string; 
//ie: b occurs no more times than a; c occurs no more times than b; etc.
//
//Given a string, check whether it is beautiful.
//
//Example
//
//For inputString = "bbbaacdafe", the output should be isBeautifulString(inputString) = true.
//
//This string contains 3 as, 3 bs, 1 c, 1 d, 1 e, and 1 f(and 0 of every other letter), 
//so since there aren't any letters that appear more frequently than the previous letter, this string qualifies as beautiful.
//
//For inputString = "aabbb", the output should be isBeautifulString(inputString) = false.
//
//Since there are more bs than as, this string is not beautiful.
//
//For inputString = "bbc", the output should be isBeautifulString(inputString) = false.
//
//Although there are more bs than cs, this string is not beautiful because there are no as, so therefore there are more bs than as.


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


bool isBeautifulString(std::string inputString) {
	
	char c = 97;
	std::vector<int> count_char;
	while (c <= 122)
	{
		int count = std::count(inputString.begin(), inputString.end(), c);
		count_char.push_back(count);
		c++;
	}
	
	for (int i = 0; i < count_char.size() - 1; i++)
	{
		int j = i + 1;
		if (count_char[i] < count_char[j])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	std::string inputString = "zaa";
	if (isBeautifulString(inputString) == true)
		std::cout << "True!";
	else
		std::cout << "False!";
	return 0;
}
