#ifndef __ARRAYPROBLEMS_H
#define __ARRAYPROBLEMS_H


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


class ArrayProblems
{
    public:
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
        vector<int> reverseArray(vector<int> a);

        /**
         * @brief 
         * 
         * Complete the 'dynamicArray' function below.
         * 
         * The function is expected to return an INTEGER_ARRAY.
         * The function accepts following parameters:
         * @param n INTEGER
         * @param queries 2D_INTEGER_ARRAY
         * @return vector<int> 
         */
        vector<int> dynamicArray(int n, vector<vector<int>> queries);

        /**
         * @brief   There is a collection of input strings and a collection of query strings. For each query string, 
         *          determine how many times it occurs in the list of input strings. Return an array of the results.
         * @example strings = ['ab', 'ab', 'abc]
         *          queries = ['ab', 'abc, 'bc']
         * 
         *          There are 2 instances of 'ab', 1 of 'abc' and 0 of 'bc. For each query, add an element to the 
         *          return array, results = [2,1,0]
         * 
         * @param strings 
         * @param queries 
         * @return vector<int> 
         */
        vector<int> matchingStrings(vector<string> strings, vector<string> queries);

        /**
         * @brief 
         * A left rotation operation on an array of size n shifts each of the array's elements 1 unit to the left. 
         * Given an integer, 'd' , rotate the array that many steps left and return the result. 
         * 
         * @param d the times for rotating
         * @param arr the array for rotating
         * @return vector<int> return the rotated array
         */
        vector<int> rotateLeft(int d, vector<int> arr);

    private:
        /**
         * @brief method for display the array
         * 
         */
        void printArray();

    private:
        /**
         * @brief saving integer array
         * 
         */
        vector<int> m_integerArray;

        /**
         * @brief saving string array
         * 
         */
        vector<string> m_stringArray;

        /**
         * @brief saving double array;
         * 
         */
        vector<double> m_doubleArray;

        /**
         * @brief saving char array;
         * 
         */
        vector<char> m_charArray;

};



#endif