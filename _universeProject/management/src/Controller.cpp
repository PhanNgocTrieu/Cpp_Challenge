#include "Controller.h"

namespace staffManagement {
    
    flowController::flowController() {
        this->m_Console = new Display();
    }

    flowController::~flowController() {
        if (m_Console) {
            delete m_Console;
            m_Console = nullptr;
        }
    }

    void flowController::welcomeScreen() {
        m_Console->_MenuScreen();
    }

    void flowController::mainFlow() {

    }

    void flowController::run() {
        this->welcomeScreen();
    }
}