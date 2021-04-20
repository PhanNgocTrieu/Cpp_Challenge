//Find the leftmost digit that occurs in a given string.
//
//Example
//
//For inputString = "var_1__Int", the output should be
//firstDigit(inputString) = '1';
//For inputString = "q2q-q", the output should be
//firstDigit(inputString) = '2';
//For inputString = "0ss", the output should be
//firstDigit(inputString) = '0'.

#include <iostream>
#include <string>

char firstDigit(std::string inputString) {
	char numb = NULL;
	for (int i = 0; i < inputString.length(); i++)
	{
		int value_i = inputString[i];
		std::cout << value_i << " is letter " << inputString[i] << std::endl;
		if (value_i >= 48 && value_i <= 57)
		{
			numb = inputString[i];
			break;
		}
	}
	
	return numb;
}


int main()
{
	std::string inputString = "var__1_in";
	std::cout << "Letter: " << firstDigit(inputString);
}
