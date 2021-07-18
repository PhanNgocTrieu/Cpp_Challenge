/*
Define crossover operation over two equal-length strings A and B as follows:

the result of that operation is a string of the same length as the input strings
result[i] is either A[i] or B[i], chosen at random
Given array of strings inputArray and a string result, 
find for how many pairs of strings from inputArray the result of the crossover operation over them may be equal to result.

Note that (A, B) and (B, A) are the same pair. 
Also note that the pair cannot include the same element of the array twice 
(however, if there are two equal elements in the array, they can form a pair).

Example

For inputArray = ["abc", "aaa", "aba", "bab"] and result = "bbb", the output should be
stringsCrossover(inputArray, result) = 2.
*/


#include <iostream>
#include <vector>
using namespace std;

int stringsCrossover(vector<string> inputArray, string result) {
    int count = 0;
    int len = inputArray.size();
    string checking = "";
    for (int idex = 0; idex < len - 1; idex++)
    {
        string s1 = inputArray[idex];
        if (s1.length() == result.length())
        {
            for (int jdex = idex + 1; jdex < len; jdex++)
            {
                string s2 = inputArray[jdex];
                
                if (s2.length() == result.length())
                {
                    int lenRun = result.length();
                    for (int run = 0; run < lenRun; run++)
                    {
                        if (s1[run] == result[run])
                        {
                            checking += s1[run];
                        }
                        else
                            checking += s2[run];
                    }
                    if (checking == result)
                        count++;
                    checking = "";
                }

            }   
        }
        
    }
    return count;
}


int main()
{
    vector<string> inputArr = {"abc", "aaa", "aba", "bab"};
    string res = "bbb";
    cout << stringsCrossover(inputArr,res) << endl;

    return 0;
}