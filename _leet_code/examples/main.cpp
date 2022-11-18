#include "common.h"
#include "easyLevel.h"
#include "mediumLevel.h"
#include "hardLevel.h"

using namespace leetcode;

int main()
{
    leetcode::easyLevel* easylevelController = new easyLevel();
    leetcode::mediumLevel* mediumlevelController = new mediumLevel();
    leetcode::hardLevel* hardlevelController = new hardLevel();
    std::cout << "Hello world from LeetCode!" << std::endl;
    mediumlevelController->maxArea(std::vector<int>{
        2,3,5,3,6,5
    });

    if (easylevelController) {
        delete easylevelController;
        easylevelController = nullptr;
    }

     if (mediumlevelController) {
        delete mediumlevelController;
        mediumlevelController = nullptr;
    }

     if (hardlevelController) {
        delete hardlevelController;
        hardlevelController = nullptr;
    }
    
    return 0;
}