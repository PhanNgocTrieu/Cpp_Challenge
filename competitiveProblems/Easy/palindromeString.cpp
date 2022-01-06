#include <iostream>
using namespace std;

bool palindromeString(string str)
{
    int left = 0;
    int right = str.length() - 1;
    while (left < right)
    {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main()
{
    if (palindromeString("abcba"))
    {
        cout << "a palindrome String!" << endl;
    }
    if ( !palindromeString("abcde"))
    {
        cout << "Not a palindrome String!" << endl;
    }
    return 0;
}