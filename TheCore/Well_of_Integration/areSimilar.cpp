/*
Two arrays are called similar if one can be obtained from another by swapping at most one pair of elements in one of the arrays.

Given two arrays a and b, check whether they are similar.

Example

For a = [1, 2, 3] and b = [1, 2, 3], the output should be
areSimilar(a, b) = true.

The arrays are equal, no need to swap any elements.

For a = [1, 2, 3] and b = [2, 1, 3], the output should be
areSimilar(a, b) = true.

We can obtain b from a by swapping 2 and 1 in b.

For a = [1, 2, 2] and b = [2, 1, 1], the output should be
areSimilar(a, b) = false.

Any swap of any two elements either in a or in b won't make a and b equal.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool areSimilar(vector<int> a,vector<int> b)
{
    if (a.size() != b.size())
        return false;
    int len = a.size();
    int diff = 0;
    int saveA_1;
    int saveA_2;
    int saveB_1;
    int saveB_2;
    int i = 0;
    for (int iRun = 0; iRun < len; iRun++)
    {
        if (a[iRun] != b[iRun])
        {
            diff++;
            cout << "diff: " << diff << endl;
            if (diff == 1)
            {
                saveA_1 = a[iRun];
                saveB_1 = b[iRun];
            }
        }

        
        if (diff >= 2)
        {
           
            if (i == 0)
            {
                if (diff == 2)
                {
                    saveA_2 = a[iRun];
                    saveB_2 = b[iRun];         
                }
                i++;
            }
            else
            {
                if (diff > 2)
                {
                    return false;
                }
            }
        }
    }
    if (diff == 1)
    {
        return false;
    }
    if (diff == 2)
    {
        if (saveA_1 != saveB_2 || saveB_1 != saveA_2)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {1, 2, 3};
    vector<int> arr3 = {1, 2, 3, 4};
    vector<int> arr4 = {1, 4, 2, 3};
    vector<int> arr5 = {1, 2, 3, 4, 7};
    vector<int> arr6 = {1, 7, 2, 3, 1};
    if (areSimilar(arr1, arr2))
    {
        cout << "True!" << endl;
    }
    else
    {
        cout << "False!" << endl;
    }

    if (areSimilar(arr3, arr4))
    {
        cout << "True!" << endl;
    }
    else
    {
        cout << "False!" << endl;
    }

    if (areSimilar(arr5, arr6))
    {
        cout << "True!" << endl;
    }
    else
    {
        cout << "False!" << endl;
    }
    return 0;
}