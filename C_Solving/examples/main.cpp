#include "solvingC.h"
#include <iostream>

using namespace C_Solving_Unit;

int main(int argc, char* argv[])
{
    char* arrOfNumber[5];
    // Deso2::solvingPerfectNumber(arrOfNumber,5);

    /**
     * @brief Deso3
     * 
     */

    /* 
    std::cout << "---------PASCAl---------" << std::endl;
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 10; j > i; j--)
            std::cout << " ";

        for (int j = 0; j <= i; j++) {
            std::cout << Deso3::C(j, i) << " ";
        }
        std::cout << std::endl;
    }
    */

    /*
    std::cout << "Doing test for removed-perfectNumber array!\n";
    Deso3::solvingRemovingPerfectNumber(arrOfNumber,5);
    */

    necessary::enter2DArray(arrOfNumber, 5);
    necessary::print2DArray(arrOfNumber, 5);
    Deso2::solvingPerfectNumber(arrOfNumber, 5);

    /**
     * @brief Deso 4
     * 
     */
    return 0;
}