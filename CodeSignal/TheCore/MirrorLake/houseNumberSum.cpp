//A boy is walking a long way from school to his home.To make the walk more fun he decides to add up all the numbers of the houses
//that he passes by during his walk.Unfortunately, not all of the houses have numbers written on them,
// and on top of that the boy is regularly taking turns to change streets, so the numbers don't appear to him in any particular order.
//
//At some point during the walk the boy encounters a house with number 0 written on it, which surprises him so much that he stops adding numbers to his total right after seeing that house.
//
//For the given sequence of houses determine the sum that the boy will get.It is guaranteed that there will always be at least one 0 house on the path.
//
//Example
//
//For inputArray = [5, 1, 2, 3, 0, 1, 5, 0, 2], the output should be
//houseNumbersSum(inputArray) = 11.
//
//The answer was obtained as 5 + 1 + 2 + 3 = 11.


#include <iostream>
#include <vector>

using namespace std;

int houseNumbersSum(vector<int> inputArray) {
    int res = 0;
    for (int i : inputArray)
    {
        if (i == 0)
            return res;
        res += i;
    }
    return res;
}

int main()
{
    vector<int> inputArray{ 1,2,3,4,6,9,12,0,3,2,1,54,2,1 };
    std::cout << houseNumbersSum(inputArray);
    return 0;
}