#include "../include/solvingC.h"
#include <debug/array>
using namespace C_Solving_Unit;

bool isPerfectNumber(const int& _number)
{
    int _sum = 0;
    int _i = 0;
    while (_i <= _number / 2)
    {
        if (_number % _i == 0)
            _sum += _i;
        _i++;
    }
    
    if (_sum == _number)
    {
        return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
    // char* arrOfNumber[5];
    // m_2.solvingPerfectNumber(&arrOfNumber[0], 5);
    if (Deso2::isPerfect(6))
        printf("Perfect Number!\n");
    return 0;
}