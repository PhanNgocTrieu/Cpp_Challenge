/*
Consider the following ciphering algorithm:

For each character replace it with its code.
Concatenate all of the obtained numbers.
Given a ciphered string, return the initial one if it is known that it consists only of lowercase letters.

Note: here the character's code means its decimal ASCII code, 
the numerical representation of a character used by most modern programming languages.

Example

For cipher = "10197115121", the output should be
decipher(cipher) = "easy".

Explanation: charCode('e') = 101, charCode('a') = 97, charCode('s') = 115 and charCode('y') = 121.
*/

#include <iostream>
using namespace std;

string decipher(string cipher) {
    string res = "";
    int sum = 0;
    int i = 0;
    for (char c : cipher)
    {
        sum = sum*10 + ((int)c - '0');

        if (sum >= 97 && sum <= 122)
        {
            char letter = (char)sum;
            res += letter;
            sum = 0;
        }
    }
    return res;
}


int main()
{
    return 0;
}