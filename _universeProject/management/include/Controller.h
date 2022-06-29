#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Display.h"
#include "Employee.h"
#include "Developer.h"
#include "common.h"

namespace staffManagement {

    class flowController {
        public:
            flowController();
            ~flowController();
            void run();
        
        protected:
            void welcomeScreen();
            void mainFlow();


        protected:
            void search(const std::string& _account);
            void search(const uint32_t& _ID);
            
            void sort(const uint32_t& _typeOfSort);
            
            void filter(const std::string& _account);
            void filter(const uint32_t& _ID);


        private:
            Display* m_Console;
            std::vector<_Employee*> listOfEmployees;
            std::unordered_map<uint32_t, _Developer*> listOfDevelopers;
    };

}

#endif // CONTROLLER_H