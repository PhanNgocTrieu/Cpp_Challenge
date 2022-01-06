/*
Given an array of 2k integers (for some integer k), 
perform the following operations until the array contains only one element:

    On the 1st, 3rd, 5th, etc. iterations (1-based) replace each pair of consecutive elements with their sum;
    On the 2nd, 4th, 6th, etc. iterations replace each pair of consecutive elements with their product.

After the algorithm has finished, there will be a single element left in the array. Return that element.

Example

For inputArray = [1, 2, 3, 4, 5, 6, 7, 8], the output should be
arrayConversion(inputArray) = 186.

We have [1, 2, 3, 4, 5, 6, 7, 8] -> [3, 7, 11, 15] -> [21, 165] -> [186], so the answer is 186.
*/

#include <iostream>
#include <vector>
using namespace std;

int arrayConversion(vector<int> inputArray)
{
    if (inputArray.size() == 1)
        return inputArray[0];

    int control = 0;
    while (inputArray.size() > 2)
    {
        control++;
        vector<int> us;
        if (control % 2 != 0)
        {
            for (int idex = 0; idex < inputArray.size(); idex = idex + 2)
            {
                us.push_back(inputArray[idex] + inputArray[idex + 1]);
            }
        }
        else
        {
            for (int idex = 0; idex < inputArray.size(); idex = idex + 2)
            {
                us.push_back(inputArray[idex] * inputArray[idex + 1]);
            }
        }
        inputArray = us;
    }

    if (control % 2 != 0)
    {
        return (inputArray[0] * inputArray[1]);
    }
    return (inputArray[0] + inputArray[1]);
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8};
    cout << "Res: " << arrayConversion(arr) << endl;
    return 0;
}