/*
You have a long strip of paper with integers written on it in a single line from left to right. 
You wish to cut the paper into exactly three pieces such 
that each piece contains at least one integer and the sum of the integers in each piece is the same. 
You cannot cut through a number, i.e. each initiRunl number will unambiguously belong to one of the pieces after cutting. 
How many ways can you do it?

It is guaranteed that the sum of all elements in the array is divisible by 3.

Example

For a = [0, -1, 0, -1, 0, -1], the output should be
threeSplit(a) = 4.

Here are all possible ways:

[0, -1] [0, -1] [0, -1]
[0, -1] [0, -1, 0] [-1]
[0, -1, 0] [-1, 0] [-1]
[0, -1, 0] [-1] [0, -1]
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int sumSplit(vector<int> a, int pos, int size)
{
    int sum = 0;
    // pos = 0 ---- > size == 0
    for (int idex = pos; idex <= size; idex++)
    {
        sum += a[idex];
    }
    return sum;
}
int threeSplit(vector<int> a)
{
    int len = a.size();
    // checking whole array has sum of all elems is divisible 3;
    if (sumSplit(a, 0, len - 1) % 3 != 0)
    {
        return 0;
    }
    int ways = 0;

    for (int iFir = 0; iFir < len - 2; iFir++)
    {
        int sumFir = sumSplit(a, 0, iFir); // sum(a,0,0---len-2);
        int iSecond = iFir + 1;
        while (iSecond < len - 1)
        {
            // sum(a,1,0----len-1);
            int sumSec = sumSplit(a, iFir + 1, iSecond);
            if (sumSec == sumFir)
            {
                int iThird = iSecond + 1;
                int sumThir = sumSplit(a, iSecond + 1, len - 1);
                if (sumThir == sumSec)
                {
                    ways++;
                }
            }
            iSecond++;
        }
    }

    return ways;
}

int main()
{
    vector<int> arr2 = {0, -1, 0, -1, 0, -1};
    cout << threeSplit(arr2) << endl;

    vector<int> arr = {0, 1, 0, 1, 0, 1};
    cout << threeSplit(arr) << endl;

    
    return 0;
}