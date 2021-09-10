//A media access control address(MAC address) is a unique identifier assigned to network interfaces
//for communications on the physical network segment.
//
//The standard(IEEE 802) format for printing MAC - 48 addresses in human -
//friendly form is six groups of two hexadecimal digits(0 to 9 or A to F), separated by hyphens(e.g. 01 - 23 - 45 - 67 - 89 - AB).
//
//Your task is to check by given string inputString whether it corresponds to MAC - 48 address or not.
//
//Example
//
//For inputString = "00-1B-63-84-45-E6", the output should be
//isMAC48Address(inputString) = true;
//For inputString = "Z1-1B-63-84-45-E6", the output should be
//isMAC48Address(inputString) = false;
//For inputString = "not a MAC-48 address", the output should be
//isMAC48Address(inputString) = false.



#include <iostream>
#include <string>

bool isMAC48Address(std::string inputString) {

	int len = inputString.length();
	int count_hyphens = 0;
	int count_letter = 0;
	for (int i = 0; i < len; i++)
	{
		int c = inputString[i];
		if (c == 45)
		{
			count_hyphens++;
			count_letter++;
			if (count_hyphens > 5)
			{
				return false;
			}
		}
		else
		{
			if ((c < 48 || c > 57) && (c < 65 || c > 70))
			{
				return false;
			}
			count_letter++;
		}
	}
	std::cout << count_hyphens << "\n";
	std::cout << count_letter << "\n";
	if (count_hyphens < 5)
	{
		return false;
	}
	if ((count_letter < 17) || (count_letter > 17))
	{
		return false;
	}
	return true;
}



int main()
{
	std::string inputString = "FF-FF-FF-FF-FF-FF";
	if (isMAC48Address(inputString) == true)
	{
		std::cout << "True!";
	}
	else
	{
		std::cout << "False";
	}
	return 0;
}
