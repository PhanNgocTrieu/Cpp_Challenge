// Given some integer, find the maximal number you can obtain by deleting exactly one digit of the given number.

// Example

// For n = 152, the output should be
// deleteDigit(n) = 52;
// For n = 1001, the output should be
// deleteDigit(n) = 101.


#include <iostream>
#include <math.h>
int deleteDigit(int n) {
    int max = 0;
    int i = 1;
    do
    {

        //Let us analyze this approach for N = 6358, K = 1
        //The different possibilities after removal of every digit once are as follows:
        //(6358 / 10) * 1 + 6358 % 1 = 635 + 0 = 635
        //(6358 / 100) * 10 + 6358 % 10 = 630 + 8 = 638
        //(6358 / 1000) * 100 + 6358 % 100 = 600 + 58 = 658
        //(6358 / 10000) * 1000 + 6358 % 1000 = 0 + 358 = 358
        int haff_second = n % i;
        int haff_first = (n / (i * 10)) * i;
        int res = haff_first + haff_second;
        if (max < res)
            max = res;
        std::cout << "max: " << max << "\n";
        i *= 10;
    } while (i < n);


    return max;
}


int main()
{
    int n = 12221; // output should be 2221
    std::cout << deleteDigit(n);
    return 0;
}
