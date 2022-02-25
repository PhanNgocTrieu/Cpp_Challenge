#include "codeForce.h"

namespace codeForce
{
    namespace testCase
    {
        void solve(void (*__functionForTest)())
        {
            int _testcase;
            std::cin >> _testcase;

            do
            {
                __functionForTest();
            }while(_testcase--);
        }
    };
};


