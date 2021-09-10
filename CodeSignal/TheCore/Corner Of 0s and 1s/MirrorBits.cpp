// Reverse the order of the bits in a given integer.

// Example

// For a = 97, the output should be
// mirrorBits(a) = 67.

// 97 equals to 1100001 in binary, which is 1000011 after mirroring, and that is 67 in base 10.

// For a = 8, the output should be
// mirrorBits(a) = 1.


#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

void sum_n(stack<int> &s, int n){
    int sum = 0;
    while (n != 0)
    {
        int temp = n % 2;
        s.push(temp);
        n = n / 2;
    }

}

int mirrorBits(int a) {
    int res = 0;
    stack<int> s;
    sum_n(s,a);
    int i = 0;
    while (!s.empty())
    {
        int temp = s.top();
        res += temp*pow(2,i);
        i++;
        s.pop();
    }
    
    return res;
}


int main()
{
    std::cout << mirrorBits(19);
    return 0;
}