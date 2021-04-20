/*
You are given a two-digit integer n. Return the sum of its digits.

Example

For n = 29, the output should be
addTwoDigits(n) = 11.
*/

#include <iostream>


int addTwoDigits(int n) {
    int temp=0;
    int sum=0;
    temp=n%10;
    n=n/10;
    sum=temp+n;

    return sum;
}

int main()
{
    int integer;
    std::cout<<"Enter the value of interger: ";
    std::cin >> integer;
    
    addTwoDigits(integer);

}