#ifndef __DTST_H__
#define __DTST_H__

#include <iostream>
using namespace std;

namespace DTST
{
    template <class _Typ>
    struct SinglyLinkedListNode
    {
        // value with type of _Typ
        _Typ m_value;

        // pointer to the next node
        SinglyLinkedListNode* next;

        public: 
            SinglyLinkedListNode() {};
            SinglyLinkedListNode(const _Typ& value) : m_value{value}, next{nullptr}
            {}
            ~SinglyLinkedListNode() {};
            
            void push_frontIntValue(const _Typ& _value) 
            {
                SinglyLinkedListNode* newNode = SinglyLinkedListNode(_value)
                if (this == nullptr)
                {
                    this = newNode;
                    return;
                }

                newNode->next = this;
                this = newNode;
            }

            void print()
            {
                SinglyLinkedListNode* iRun = this;

                while (iRun != nullptr && iRun->next != nullptr)
                {
                    cout << iRun->m_value << " -> ";
                }
                cout << endl;
            }
    };

    class LinkedListProblems
    {
                   
        public:
            /**
             * @brief Construct a new Linked List Problems object
             * 
             */
            LinkedListProblems();

            /**
             * @brief Destroy the Linked List Problems object
             * 
             */
            ~LinkedListProblems();

            /**
             * @brief 
             * You’re given the pointer to the head nodes of two linked lists. 
             * Compare the data in the nodes of the linked lists to check if they are equal. 
             * If all data attributes are equal and the lists are the same length, return 1. 
             * Otherwise, return 0.
             * 
             * @param list1 first linked list
             * @param list2 second linked list
             * 
             * @return return the resulting of 2 lists
             */
            bool compare_lists(SinglyLinkedListNode<int>* list1, SinglyLinkedListNode<int>* list2);

            /**
             * @brief Giving a list -> reversing the given list
             * 
             * @param head the pointer to the list
             * @return SinglyLinkedListNode* return the reversed list
             */
            SinglyLinkedListNode<int>* reverse(SinglyLinkedListNode<int>* head);

            /**
             * @brief   
             * Given pointers to the heads of two sorted linked lists, merge them into a single, sorted linked list. 
             * Either head pointer may be null meaning that the corresponding list is empty.
             * 
             * @param head1 pointer to the first list
             * @param head2 pointer to the second list
             * @return SinglyLinkedListNode<int>* return the merged list from 2 lists
             */
            SinglyLinkedListNode<int>* mergeLists(SinglyLinkedListNode<int>* head1, SinglyLinkedListNode<int>* head2);

        private:
            void printLinkedList();

        private:
            SinglyLinkedListNode<int>* m_intLinkedList;
            SinglyLinkedListNode<float>* m_floatLinkedList;
            SinglyLinkedListNode<double>* m_doubleLinkedList;
            SinglyLinkedListNode<string>* m_stringLinkedList;
            
    };


};



#endif