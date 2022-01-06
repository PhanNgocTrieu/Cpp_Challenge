/*
Difficulty Level : Easy
You are given a list of n-1 integers and these integers are in the range of 1 to n. 
There are no duplicates in the list. One of the integers is missing in the list. 
Write an efficient code to find the missing integer.
*/

#include <iostream>

void solve(int* _numberList, int _size)
{
    int _firstNumb = 1;
    int _secondNumb = _numberList[0];


    for (int index = 2; index <= _size + 1; index++)
    {
        // from 1 ^ 2 ^ 3 ^ 3 
        _firstNumb ^= index;      
        printf("_firstNum: %d = %d\n", index,_firstNumb);  
    }

    for (int index = 1; index < _size; index++)
    {
        // from arr[0] ^ arr[1] ^ arr[2] ^ .... ^ arr[n]
         _secondNumb ^= _numberList[index];
         printf("Array's elems:%d = %d\n",index, _secondNumb);
    }
    printf("Result: %d\n", (_firstNumb ^ _secondNumb));

}

int main()
{
    int arr[] = {1,2,3,4,6,8,7};
    solve(arr,7);

    return 0;
}