#include <iostream>
#include "dataStructure.h"
#include "linkedlist.h"

int main()
{
    linkedlist<int>* list = nullptr;
    linkedlist<int>* list2 = nullptr;
    DTST::LinkedListProblems m_llProblems;
    m_llProblems.initializingLinkedList(list, std::vector<int>({
        1,2,3,4,5
    }));
    m_llProblems.initializingLinkedList(list2, std::vector<int>({
        1,2,3,5,6
    }));
    // m_llProblems.reverse(list);
    m_llProblems.mergeLists(list, list2);
    

    return 0;
}