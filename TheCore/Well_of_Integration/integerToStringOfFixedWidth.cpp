/*
Given a positive integer number and a certain length, we need to modify the given number to have a specified length. 
We are allowed to do that either by cutting out leading digits 
(if the number needs to be shortened) or by adding 0s in front of the original number.

Example:

For number = 1234 and width = 2, the output should be
integerToStringOfFixedWidth(number, width) = "34";
For number = 1234 and width = 4, the output should be
integerToStringOfFixedWidth(number, width) = "1234";
For number = 1234 and width = 5, the output should be
integerToStringOfFixedWidth(number, width) = "01234".
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

int mPow(const int &_value, int base)
{
    int res = 1;
    while (base > 0)
    {
        res *= _value;
        base--;
    }
    return res;
}

int splitNumber(int _number, int width, int &count)
{
    int res = 0;
    while (_number > 0 && count < width)
    {
        int temp = _number % 10;
        res = mPow(10, count) * temp + res;
        _number = _number / 10;
        count++;
    }
    // 1234
    // 10^0 = 1*4 = 4 - count = 1
    // 10^1 = 10*3 + 4 = 34 = count = 2
    // 10^2 = 100*2 + 34 = 234 - count = 3
    // 10^3 = 1000*1 + 234 = 1234 - count = 4
    return res;
}

string integerToStringOfFixedWidth(int number, int width)
{
    string res = "";
    int countWidth = 0;
    if (number == 0)
    {
        while (countWidth < width)
        {
            res.append("0");
            countWidth++;
        }
        return res;
    }
    int _number = number;
    int _splitValue = splitNumber(_number, width, countWidth); // 34

    if (countWidth < width)
    {
        while (countWidth < width)
        {
            res.append("0");
            countWidth++;
        }
        res.append(to_string(number));
        return res;
    }
    res.append(to_string(_splitValue));

    return res;
}

int main()
{
    cout << integerToStringOfFixedWidth(1234, 5) << endl;
    cout << integerToStringOfFixedWidth(1234, 2) << endl;
    cout << integerToStringOfFixedWidth(0, 10) << endl;
    return 0;
}