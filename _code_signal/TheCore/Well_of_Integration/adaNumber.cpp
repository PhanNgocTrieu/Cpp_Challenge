/*
Consider two following representations of a non-negative integer:

A simple decimal integer, constructed of a non-empty sequence of digits from 0 to 9;
An integer with at least one digit in a base from 2 to 16 (inclusive), enclosed between # characters, and preceded by the base, 
which can only be a number between 2 and 16 in the first representation. 
For digits from 10 to 15 characters a, b, ..., f and A, B, ..., F are used.

Additionally, both representations may contain underscore (_) characters; 
they are used only as separators for improving legibility of numbers and can be ignored while processing a number.

Your task is to determine whether the given string is a valid integer representation.

Note: this is how integer numbers are represented in the programming language Ada.

Example

For line = "123_456_789", the output should be
adaNumber(line) = true;
For line = "16#123abc#", the output should be
adaNumber(line) = true;
For line = "10#123abc#", the output should be
adaNumber(line) = false;
For line = "10#10#123ABC#", the output should be
adaNumber(line) = false;
For line = "10#0#", the output should be
adaNumber(line) = true;
For line = "10##", the output should be
adaNumber(line) = false.

*/
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

bool checking(string base, string presentation)
{
    int digitCount = 0;
    if (  presentation == "" )
    {
        return false;
    }
    char letterBelowLimit;
    char letterUpponLimit = 'A';
    if (stoi(base) > 10)
    {
        letterBelowLimit = 'A';
        letterUpponLimit += (stoi(base) - 10) - 1; // base 13: -> limit = A + 3 = ABCD -> D
        cout << "base: " << base << endl;
        for (char c : presentation)
        {
            cout << "C : " << c << endl;
            if (!((c >= '0' && c <= '9') || (c >= letterBelowLimit && c <= letterUpponLimit) || (c >= letterBelowLimit + 32 && c <= letterUpponLimit + 32) || c == '_' ))
            {
                return false;
            }
            if ((c >= '0' && c <= '9') || (c >= letterBelowLimit && c <= letterUpponLimit) || (c >= letterBelowLimit + 32 && c <= letterUpponLimit + 32))
                digitCount++;
        }
        
        if (digitCount == 0)
        {
            return false;
        }
        return true;
    }
    else
    {
        letterBelowLimit = '0';
        letterUpponLimit = '0' + stoi(base) - 1;
        for (char c : presentation)
        {
            cout << "C : " << c << endl;
            if (!((c >= letterBelowLimit && c <= letterUpponLimit) || c =='_'))
            {
                return false;
            }
            if ((c >= '0' && c <= '9'))
                digitCount++;
        }
        if (digitCount == 0)
        {
            return false;
        }
        return true;
    } 
}

bool noHastag(char c)
{
    if (!((c >= '0' && c <= '9') || c == '_'))
    {
        return false;
    }
    return true;
}

int countDigit(const string& _line)
{
    int count = 0;
    for (char c : _line)
    {
        if (c >= '0' && c <= '9')
            count++;
    }
    return count;
}

string convertBase(string base)
{
    string base_result = "";
    for (char c : base)
    {
        if (c == '_')
            continue;
        base_result += c;
    }
    return base_result;
}

bool adaNumber(string line)
{

    if (line[0] == '#')
    {
        return false;
    }

    int count_hastag = count(line.begin(), line.end(), '#');
    int existUnderscore = count(line.begin(), line.end(), '_');

    if (count_hastag >= 3 || count_hastag == 1)
    {
        return false;
    }
    
    if (countDigit(line) == 0)
    {
        return false;
    }
    
    if (count_hastag == 0)
    {
        // checking for underscore
        for (char c : line)
        {
            if (!noHastag(c))
            {
                return false;
            }
        }
        return true;
    }

    int iPushing = 0;
    string base;
    string presentation;

    stringstream ss(line);
    string word;
    while (getline(ss, word, '#'))
    {
        if (iPushing == 0)
        {
            base = word;
        }
        else
        {
            presentation = word;
        }
        iPushing++;
    }
    
    base = convertBase(base);
    
    cout << "Base: " << base << endl;
    cout << "Presentation: " << presentation << endl;

    if (stoi(base) > 16 || stoi(base) < 2)
    {
        return false;
    }
    return checking(base, presentation);  
}

int main()
{
    if (adaNumber("123_456_789"))
        cout << "123_456_789 -- " << "True!" << endl;
    if (adaNumber("10#123456789#"))
        cout << "10#123456789# -- " << "True!" << endl;
    if (adaNumber("9##"))
        cout << "9##: -- " << "True!" << endl;
    if (adaNumber("10#10#123ABC#"))
        cout << "10#10#123ABC#: -- "<< "True!" << endl;
    if (adaNumber("10#123abc#"))
        cout << "10#123abc#: -- " << "True!" << endl;
    if (adaNumber("13#aaaa_____8cccccbbbc___c_cc#"))
        cout << "13#aaaa_____8cccccbbbc___c_cc#:" << " -- " << "True!" << endl;
        
    return 0;
}