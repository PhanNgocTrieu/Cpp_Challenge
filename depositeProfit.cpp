//You have deposited a specific amount of money into your bank account.
//Each year your balance increases at the same growth rate.
//With the assumption that you don't make any additional deposits, 
//find out how long it would take for your balance to pass a specific threshold.
//
//Example
//
//For deposit = 100, rate = 20, and threshold = 170, the output should be
//depositProfit(deposit, rate, threshold) = 3.
//
//Each year the amount of money in your account increases by 20 % .So throughout the years, your balance would be :
//
//year 0 : 100;
//year 1: 120;
//year 2: 144;
//year 3: 172.8.
//Thus, it will take 3 years for your balance to pass the threshold, so the answer is 3.

#include <iostream>
#include <time.h>
#include <vector>


int depositProfit(int deposit, int rate, int threshold) {
    int year = 0;
    float growth = rate / float(100);
    float deposit_temp = deposit;
    while (deposit_temp < threshold)
    {
        year++;
        deposit_temp += deposit_temp * growth;
    }
    return year;
}


int main()
{
    int deposit[50];
    int rate[50];
    int threshold[50];
    for (int i = 0; i < 50; i++)
    {
        deposit[i] = rand() % 100 + 1;
        rate[i] = rand() % 100 + 1;
        threshold[i] = rand() % 200 + 1;
        std::cout << "#Testcase" << i << ": " << depositProfit(deposit[i], rate[i], threshold[i]) << std::endl;
    }
    
    return 0;
}
