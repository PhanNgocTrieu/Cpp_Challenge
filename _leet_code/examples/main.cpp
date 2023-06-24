#include "easyLevel.h"
#include "mediumLevel.h"
#include "hardLevel.h"

using namespace leetcode;

void reallocated(void * temp) {
    if (temp) {
        delete temp;
        temp = nullptr;
    }
}

int main()
{
    leetcode::easyLevel* easylevelController = new easyLevel();
    leetcode::mediumLevel* mediumlevelController = new mediumLevel();
    leetcode::hardLevel* hardlevelController = new hardLevel();

    std::vector<int> input = {1,2,3};
    auto getVal = mediumlevelController->wordSubsets(
        vector<string>{"amazon","apple","facebook","google","leetcode"},
        vector<string>{"e","o"}
    );

    reallocated(easylevelController);
    reallocated(mediumlevelController);
    reallocated(hardlevelController);
    
    return 0;
}