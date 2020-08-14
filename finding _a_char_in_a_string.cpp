
// Enter a string and a char from keyboard!
// counting how many time of occurences of ch in str!

#include <iostream>
#include <cstring>
#include "my_header.h"
using namespace std;

int main() {
	int32_t count = 0;
	char str[50];
	cout << "Enter string: ";
	cin.getline(str, sizeof(str),'\n');


	char ch;
	cout << "Enter char that you want to search: ";
	cin >> ch;
	int32_t i=0;
	while (str[i])
	{
		str[i] == ch ? count++ : count;
		i++;
	}

	cout << "Number of ch in str are: " << count;

	return 0;

}
