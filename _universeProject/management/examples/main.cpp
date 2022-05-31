#include "Controller.h"

int main() {
    
    staffManagement::flowController* controller = new staffManagement::flowController();

    controller->run();

    return 0;
}