#include <iostream>
#include "dataStructure.h"
#include "linkedlist.h"
#include "BST.h"
int main()
{
    /**
     * @brief Linked list testing
     * 
     */

    // linkedlist<int>* list = nullptr;
    // linkedlist<int>* list2 = nullptr;
    // DTST::LinkedListProblems m_llProblems;
    // m_llProblems.initializingLinkedList(list, std::vector<int>({
    //     1,2,3,4,5
    // }));
    // m_llProblems.initializingLinkedList(list2, std::vector<int>({
    //     1,2,3,5,6
    // }));
    // // m_llProblems.reverse(list);
    // m_llProblems.mergeLists(list, list2);
    // m_llProblems.deleteNode(list2,7);
    

    /**
     * @brief BST testing
     * 
     */

    
    DTST::DTST_BST::BST<int>* root = nullptr;
    DTST::BST_Problems bstProblems;
    // initialzing a BST
    DTST::DTST_BST::insert(root, 3);
    DTST::DTST_BST::insert(root, -2);
    DTST::DTST_BST::insert(root, 1);
    DTST::DTST_BST::insert(root, 5);
    DTST::DTST_BST::insert(root, 7);
    DTST::DTST_BST::inOrderTravel(root);
    std::cout << std::endl;

    // std::cout << bstProblems.rangeSumBST(root, 2, 6) << std::endl;
    
    

    return 0;
}