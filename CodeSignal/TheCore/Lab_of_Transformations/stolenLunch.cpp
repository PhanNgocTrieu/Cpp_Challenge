/**
 * @file stolenLunch.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-10
 * 
 * @copyright Copyright (c) 2021
 * 
 * @problem:    When you recently visited your little nephew, 
 *              he told you a sad story: there's a bully at school who steals his lunch every day, 
 *              and locks it away in his locker. He also leaves a note with a strange, coded message. 
 *              Your nephew gave you one of the notes in hope that you can decipher it for him. 
 *              And you did: it looks like all the digits in it are replaced with letters and vice versa. 
 *              Digit 0 is replaced with 'a', 1 is replaced with 'b' and so on, with digit 9 replaced by 'j'.
 * 
 *              The note is different every day, 
 *              so you decide to write a function that will decipher it for your nephew on an ongoing basis.
 * 
 * @example: 
 *              For note = "you'll n4v4r 6u4ss 8t: cdja", the output should be
 *              stolenLunch(note) = "you'll never guess it: 2390".
 */


#include <iostream>
using namespace std;

char digitCipher(char c)
{
    return char((int)c - 48 + 97);
}

char letterCipher(char c)
{
    return char((int)c - 97 + 48);
}

string stolenLunch(string note) {
    if (note == "")
        return note;
    string res = "";
    for (char c : note)
    {
        if (c >= '0' && c <= '9')
        {
            res += digitCipher(c);
        }
        else
        {
            if (c >= 'a' && c <= 'j')
            {
                res += letterCipher(c);
            }
            else
            {
                res += c;
            }
        }
        
    }
    return res;
}


int main()
{ 
    // Output: "you'll never guess it: 2390"
    cout << stolenLunch("you'll n4v4r 6u4ss 8t: cdja") << endl;


    // Output: "abcdefghij"
    cout << stolenLunch("0123456789") << endl;
    return 0;
}