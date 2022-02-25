#ifndef __CODEFORCE_H__
#define __CODEFORCE_H__

#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


namespace codeForce
{
    namespace greatSequence
    {

    };


    namespace testCase
    {
        void solve(void (*__functionForTest)());
    };
};

#endif // __CODEFORCE_H__