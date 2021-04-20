// CodeMaster has just returned from shopping. He scanned the check of the items he bought and gave the resulting string to Ratiorg to figure out the total number of purchased items. Since Ratiorg is a bot he is definitely going to automate it, so he needs a program that sums up all the numbers which appear in the given input.

// Help Ratiorg by writing a function that returns the sum of numbers that appear in the given inputString.

// Example

// For inputString = "2 apples, 12 oranges", the output should be
// sumUpNumbers(inputString) = 14.

#include <iostream>
#include <string>

using namespace std;

int sumUpNumbers(string inputString) {
    int sumUpNumbers = 0;
    string temp = "";
    int i = 0;
    for (auto w : inputString)
    {
        if (w > 47 && w < 58)
        {
            temp += w;
        }
        else
        {
            if (temp.length() != 0)
            {
                std::cout << temp << endl;
                sumUpNumbers += (int)stoi(temp);
            }
            temp = "";
        }        
    }

    if (temp.size() != 0)
    {
        std::cout << temp << endl;
        sumUpNumbers += (int)stoi(temp);
    }
    


    return sumUpNumbers;
}


int main()
{
    string inputString = "there are some (12) digits 5566 in this 770 string 239";
    string output;
    
    std::cout << "Total: " << sumUpNumbers(inputString);
    return 0;
}
