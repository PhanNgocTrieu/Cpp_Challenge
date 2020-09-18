//Correct variable names consist only of English letters, 
//digitsand underscores and they can't start with a digit.
//
//Check if the given string is a correct variable name.
//
//Example
//
//For name = "var_1__Int", the output should be
//variableName(name) = true;
//For name = "qq-q", the output should be
//variableName(name) = false;
//For name = "2w2", the output should be
//variableName(name) = false.


#include <iostream>
#include <string>
#include <locale>


bool variableName(std::string name) {
	int is_number = (int)name[0];
	if (is_number >= 48 && is_number <= 57)
	{
		return false;
	}

	for (auto c : name)
	{
		if ( (c < '0' || c > '9') && (c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && c != '_')
		{
			return false;
		}
	}
	return true;
}


int main()
{
	std::string name = "a231-a12";
	if (variableName(name) == true)
	{
		std::cout << "True!" << std::endl;
	}
	else
	{
		std::cout << "False!" << std::endl;
	}
	
	return 0;
}
