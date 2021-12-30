#include "dataStructure.h"


namespace DTST
{
    LinkedListProblems::LinkedListProblems()
    {}

    LinkedListProblems::~LinkedListProblems()
    {}


    /**
     * @brief solving compare list
     *      * 
     * @remark already test -> successful
     */
    bool LinkedListProblems::compare_lists(SinglyLinkedListNode<int>* list1, SinglyLinkedListNode<int>* list2)
    {
        if (list1 == nullptr && list2 == nullptr)
            return 1;

        bool isValueEqual = true;

        while (list1 != nullptr && list2 != nullptr)
        {

            if (list1->m_value != list2->m_value)
            {
                isValueEqual = false;
                return 0;
            }
            list1 = list1->next;
            list2 = list2->next;              
     
        }
        
        if (list1 == nullptr && list2 == nullptr)
        {    
            if (isValueEqual)
                return true;
            else
                return false;
        }
        return 0; 
    }

    /**
     * @brief solving reversing list
     * 
     * @remark already test -> successful
     */
    SinglyLinkedListNode<int>* LinkedListProblems::reverse(SinglyLinkedListNode<int>* head)
    {
        SinglyLinkedListNode<int>* pre = nullptr;
        SinglyLinkedListNode<int>* curr = head;
        SinglyLinkedListNode<int>* next = nullptr;
        
        
        while (curr != NULL) {
            next = curr -> next;
            curr -> next = pre;
            pre = curr;
            curr = next;
        }
        
        return pre;
    }

    /**
     * @brief 
     * 
     * @remark 
     */
    SinglyLinkedListNode<int>* LinkedListProblems::mergeLists(SinglyLinkedListNode<int>* head1, SinglyLinkedListNode<int>* head2)
    {
        
    }



    /**
     * @brief printing the list of the method
     * 
     */
    void LinkedListProblems::printLinkedList()
    {
        // print the list of integer numbers
        if (m_intLinkedList)
        {
            m_intLinkedList->print();
        }
        
        // print the list of float numbers
        if (m_floatLinkedList)
        {
            m_floatLinkedList->print();
        }

        // print the list of double numbers
        if (m_doubleLinkedList)
        {
            m_doubleLinkedList->print();
        }

        // print the list of strings
        if (m_stringLinkedList)
        {
            m_stringLinkedList->print();
        }
    }

};