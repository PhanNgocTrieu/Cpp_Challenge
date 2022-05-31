#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Display.h"
#include "Employee.h"
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

        private:
            Display* m_Console;
            std::unordered_map<uint32_t, Employee*> listOfMember;
            std::unordered_map<uint32_t, Employee*> listOfDeveloper;
            std::unordered_map<uint32_t, Employee*> listOfManager;
    };

}

#endif // CONTROLLER_H