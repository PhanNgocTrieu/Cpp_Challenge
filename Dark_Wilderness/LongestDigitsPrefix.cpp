//Given a string, output its longest prefix which contains only digits.
//
//Example
//
//For inputString = "123aa1", the output should be
//longestDigitsPrefix(inputString) = "123".

#include <iostream>
#include <string>

std::string longestDigitsPrefix(std::string inputString) {
	std::string res;
	if (inputString[0] < 48 && inputString[0] > 57)
	{
		return res;
	}

	int i = 0;
	while (inputString[i] >= 48 && inputString[i] <= 57)
	{
		res.push_back(inputString[i]);
		i++;
	}

	return res;
}

int main()
{
	std::string inputString = "  123asdad2132";
	std::cout << longestDigitsPrefix(inputString);

	return 0;
}
