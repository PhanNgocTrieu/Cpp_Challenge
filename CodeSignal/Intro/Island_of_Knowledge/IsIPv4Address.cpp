//An IP address is a numerical label assigned to each device(e.g., computer, printer) participating in a computer network that uses the Internet Protocol for communication.There are two versions of the Internet protocol, and thus two versions of addresses.One of them is the IPv4 address.
//
//Given a string, find out if it satisfies the IPv4 address naming rules.
//
//Example
//
//For inputString = "172.16.254.1", the output should be
//isIPv4Address(inputString) = true;
//
//For inputString = "172.316.254.1", the output should be
//isIPv4Address(inputString) = false.
//
//316 is not in range[0, 255].
//
//For inputString = ".254.255.0", the output should be
//isIPv4Address(inputString) = false.
//
//There is no first number.

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<int> get_numbers(const std::string& s)
{
	//create a variable of stream:
	std::stringstream stream(s);
	std::string cur;
	std::vector<int> res;
	while (std::getline(stream, cur, '.')) // push all string except '.' in current
	{
		if (cur.size() > 1 && cur[0] == '0')
		{
			return std::vector<int>();
		}
		if (cur.size() > 3)
		{
			return std::vector<int>();
		}
		res.push_back(std::stoi(cur)); //convert from string to numbers and push in res
	}

	return res;
}
bool isIPv4Address(std::string inputString) {
	
	for (auto c : inputString)
	{ //element of strings have to get from 0 - 9 and also have dots if without it -> return false
		if ( (c < '0' || c > '9') && c != '.')
		{
			return false;
		}
	}
	// IP could not be like this: .231.231.
	if (inputString[0] == '.' || inputString.back() == '.')
	{
		return false;
	}

	// IP could not be like this: ..1232.21
	for (int i = 0; i < inputString.size() - 1; ++i)
	{
		if (inputString[i] == '.' && inputString[i + 1] == '.')
		{
			return false;
		}
	}

	auto numbers = get_numbers(inputString);
	if (numbers.size() != 4)
	{
		return false;
	}
	for (auto n : numbers)
	{
		if (n > 255)
			return false;
	}

	return true;
}


int main()
{
	std::string inputString = "172.16.254.1";
	
	if (isIPv4Address(inputString) == true)
		std::cout << "TRUE!";
	
	return 0;
}
