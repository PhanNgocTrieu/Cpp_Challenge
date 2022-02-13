#include "IOLibrary.h"

using namespace IOlib;

int main()
{
    int i = integerInput();
    std::cout << "Integer number: " << i << std::endl;
    double mDouble = doubleInput();
    std::cout << "Double number: " << mDouble << std::endl;
    return 0;
}