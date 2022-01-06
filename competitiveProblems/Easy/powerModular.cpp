#include <iostream>
using namespace std;

int power(int x, int y)
{
    int res = 1; // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res * x;

        // y must be even now
        y = y >> 1; // y = y/2
        x = x * x;  // Change x to x^2
    }

    return res;
}

int modularOfPower(const int &_x, const int &_y, const int &p)
{
    int res = power(_x,_y);

    while (res % p > p)
    {
        res = res % p;
    }
    return res % p;
}

int main()
{
    cout << modularOfPower(2,3,5) << endl;
    return 0;
}