


#include <iostream>

int sum_n(int n){
    int sum = 0;
    while (n != 0)
    {
        int temp = n % 2;
        sum += temp;
        n = n / 2;
    }
    return sum;
}

int rangeBitCount(int a, int b) {
    int res = 0;
    for (int i = a; i <= b; i++) {
        res += sum_n(i);
    }
    return res;
}


int main()
{
    std::cout << rangeBitCount(2,7);
    return 0;
}