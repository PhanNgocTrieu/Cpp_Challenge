#include "Display.h"

namespace staffManagement {

    void Display::Welcome() {

    }

    void Display::Menu() {
        std::cout << setw(30) << "*****************************************************************" << std::endl;
        std::cout << setw(30) << "*                        STAFF MANAGEMENT                       *" << std::endl;
        std::cout << setw(30) << "*****************************************************************" << std::endl;
        std::cout << setw(30) << "*      1. Adding new member                                     *" << std::endl;
        std::cout << setw(30) << "*      2. Filter                                                *" << std::endl;
        std::cout << setw(30) << "*      3. Searching Information Of Staff                        *" << std::endl;
        std::cout << setw(30) << "*      4. Removing Member                                       *" << std::endl;
        std::cout << setw(30) << "*      5. Clearing Database                                     *" << std::endl;
        std::cout << setw(30) << "*****************************************************************" << std::endl;
    }

    void Display::Filter() {

    }

};
