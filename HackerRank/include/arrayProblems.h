#ifndef __ARRAYPROBLEMS_H
#define __ARRAYPROBLEMS_H

/**
 * @brief 
 * An array is a type of data structure that stores elements of the same type in a contiguous block of memory. 
 * In an array, , of size , each memory location has some unique index,  (where ), that can be referenced as  or .
 * Reverse an array of integers.
 * 
 * Note: If you've already solved our C++ domain's Arrays Introduction challenge, you may want to skip this.
 * Example:
 *  Arr = [1,2,3]
 * Return: ơ3,2,1]
 * 
 * Function Description
 * Complete the function reverseArray in the editor below. reverseArray has the following parameter(s):
 *      int A[n]: the array to reverse
 * Returns
 *      int[n]: the reversed array
 * 
 * Input Format:    The first line contains an integer, , the number of integers in .
 *                  The second line contains  space-separated integers that make up .
 * 
 * Constraints
 *      1 <= N <= 10^3
 *      1 <= A[i] <= 10^4, where A[i] is the i_th integer in A
 * 
 * 
 */



#include <iostream>
#include <vector>
using namespace std;


class ArrayProblems
{
    public:
        /*
        * Complete the 'reverseArray' function below.
        *
        * The function is expected to return an INTEGER_ARRAY.
        * The function accepts INTEGER_ARRAY a as parameter.
        */

        vector<int> reverseArray(vector<int> a);

    private:
};



#endif