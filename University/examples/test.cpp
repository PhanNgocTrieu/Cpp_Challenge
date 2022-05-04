#include "complex.h"


int main() {
    Complex firstNumber(2.2, 3.2);
    Complex secondNumber(2.3, 2.3);

    Complex adding = firstNumber + secondNumber;
    Complex multiple = firstNumber * secondNumber;

    std::cout << "************************************************" << std::endl;
    std::cout << "Value of first number: " << firstNumber.getReal() << " + " << firstNumber.getImg() << "i\n";
    std::cout << "Value of first number: " << secondNumber.getReal() << " + " << secondNumber.getImg() << "i\n";
    std::cout << "************************************************" << std::endl;

    std::cout << "************************************************" << std::endl;
    std::cout << "Adding 2 complex numbers:" << std::endl;
    std::cout << "Value: " << adding.getReal() << " + " << adding.getImg() << "i" << std::endl;
    std::cout << "************************************************" << std::endl;
    std::cout << "************************************************" << std::endl;
    std::cout << "Multiple 2 complex numbers:" << std::endl;
    std::cout << "Value: " << multiple.getReal() << " + " << multiple.getImg() << "i" << std::endl;
    std::cout << "************************************************" << std::endl;
}