#include "Display.h"

namespace staffManagement {


    void Display::_MenuScreen() {
        std::cout << "\t\t" << "*****************************************************************" << std::endl;
        std::cout << "\t\t" << "*                        STAFF MANAGEMENT                       *" << std::endl;
        std::cout << "\t\t" << "*****************************************************************" << std::endl;
        std::cout << "\t\t" << "*      1. Adding new member                                     *" << std::endl;
        std::cout << "\t\t" << "*      2. Filter                                                *" << std::endl;
        std::cout << "\t\t" << "*      3. Searching Information Of Staff                        *" << std::endl;
        std::cout << "\t\t" << "*      4. Removing Member                                       *" << std::endl;
        std::cout << "\t\t" << "*      5. Clearing Database                                     *" << std::endl;
        std::cout << "\t\t" << "*      0. Exit                                                  *" << std::endl;
        std::cout << "\t\t" << "*****************************************************************" << std::endl;
    }

    void Display::_AddingNewMemberScreen() {
        std::cout << "\t\t" << "*****************************************************************" << std::endl;
        std::cout << "\t\t" << "*                        STAFF MANAGEMENT                       *" << std::endl;
        std::cout << "\t\t" << "*****************************************************************" << std::endl;
        std::cout << "\t\t" << "*      1. Adding a Developer                                    *" << std::endl;
        std::cout << "\t\t" << "*      2. Adding a Manager                                      *" << std::endl;
        std::cout << "\t\t" << "*      0. Exit                                                  *" << std::endl;
        std::cout << "\t\t" << "*****************************************************************" << std::endl;
    }

};
