// Given a character, check if it represents an odd digit, an even digit or not a digit at all.

// Example

// For symbol = '5', the output should be
// characterParity(symbol) = "odd";
// For symbol = '8', the output should be
// characterParity(symbol) = "even";
// For symbol = 'q', the output should be
// characterParity(symbol) = "not a digit".

#include <iostream>
using namespace std;
string characterParity(char symbol) {
    if (symbol >= '0' && symbol <= '9')
    {
        if ((int)symbol % 2 == 0)
        {
            return string("even");
        }
        return string("odd");
    }
    return string("not a digit");
}

int main()
{
    cout << characterParity('9'); // odd
    cout << characterParity('8'); // even
    cout << characterParity('q'); // not a digit
    return 0;
}