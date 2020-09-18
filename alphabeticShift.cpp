//Given a string, your task is to replace each of its characters
//by the next one in the English alphabet; 
//i.e.replace a with b, replace b with c, etc(z would be replaced by a).
//
//Example
//
//For inputString = "crazy", the output should be alphabeticShift(inputString) = "dsbaz".


#include <iostream>
#include <string>

std::string alphabeticShift(std::string inputString) {
	std::string res = "";

	for (auto c : inputString)
	{
		if (c == 'z' || c == 'Z')
		{
			c = 'a';
			res += c;
		}
		else
		{
			c = c + 1;
			res += c;
		}
	}

	return res;
}

int main()
{
	std::string inputString = "codesignal";
	std::cout << "Before shift: " << inputString << std::endl;
	std::string res = alphabeticShift(inputString);
	std::cout << "After shift: " << res << std::endl;
	return 0;
}

// result:
// Before shift: codesignal
// After shift: dpeftjhobm
