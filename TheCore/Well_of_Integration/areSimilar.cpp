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

bool areSimilar(vector<int> a, vector<int> b) {
    if (a.size() !=  b.size())
    {
        return false;
    }
    int changeCount = 0;
    for (int iRun = 0; iRun < a.size(); iRun++)
    {
        if (a[iRun] != b[iRun])
        {
            vector<int>::iterator it = find(b.begin() + iRun,b.end(),a[iRun]);
            if (it == b.end())
            {
                cout << "call note found!" << endl;
                return false;
            }
            else
            {
                swap(b[iRun],*it);
                changeCount++;
            }
            
            // for (int jRun = iRun; jRun < b.size(); jRun++)
            // {
            //     if (b[jRun] == a[iRun])
            //     {
            //         std::swap(b[iRun],b[jRun]);
            //         flag = true;
            //         changeCount++;
            //         break;
            //     }
            // }

            if (changeCount > 1)
            {
                cout << "call Change > 1!" << endl;
                return false;
            }
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