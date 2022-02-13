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

int calculate_sum_array(vector<int> a, int size)
{
    int sum = 0;
    for (int idex = 0; idex < size; idex++)
    {
        sum += a[idex];
    }

    return sum;
}
int threeSplit(vector<int> a)
{
    int ways = 0;
    int first_part = 0;
    int second_part;
    int size = a.size();
    int sum = calculate_sum_array(a, size);

    for (int i = 0; i < size - 2; i++)
    {
        first_part += a[i];
        second_part = 0;
        for (int j = i + 1; j < size - 1; j++)
        {
            second_part += a[j];
            // check first_part == second_part && first_part == sum - first_part - second_part
            if (first_part == second_part && first_part == sum - first_part - second_part)
            {
                ways++;
            }
        }
    }

    return ways;
}

int main()
{
    vector<int> arr2 = {0, -1, 0, -1, 0, -1}; // 4
    cout << threeSplit(arr2) << endl;

    vector<int> arr = {0, 1, 0, 1, 0, 1}; // 4
    cout << threeSplit(arr) << endl;

    return 0;
}