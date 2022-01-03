#ifndef __DTST_H__
#define __DTST_H__

#include "linkedlist.h"
#include <iostream>
#include <vector>

using namespace std;

namespace DTST
{
    class LinkedListProblems
    {
        public:
            LinkedListProblems();
            ~LinkedListProblems();
            void initializingLinkedList(linkedlist<int>*& list, vector<int> arrOfValue);
            
        public:
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
            bool compare_lists(linkedlist<int>* list1, linkedlist<int>* list2);

            /**
             * @brief Giving a list -> reversing the given list
             * 
             * @param head the pointer to the list
             * @return linkedlist* return the reversed list
             */
            linkedlist<int>* reverse(linkedlist<int>*& head);

            /**
             * @brief   
             * Given pointers to the heads of two sorted linked lists, merge them into a single, sorted linked list. 
             * Either head pointer may be null meaning that the corresponding list is empty.
             * 
             * @param head1 pointer to the first list
             * @param head2 pointer to the second list
             * @return linkedlist<int>* return the merged list from 2 lists
             */
            linkedlist<int>* mergeLists(linkedlist<int>* head1, linkedlist<int>* head2);

            /**
             * @brief 
             * 
             * @param llist the pointer to the list for deleting
             * @param position the position for deleting
             * @return linkedlist<int>* return the deleted list from origin list
             */
            linkedlist<int>* deleteNode(linkedlist<int>* llist, int position);

            
        private:
            void printLinkedList();

            template <class _Type>
            void addingNode(linkedlist<_Type>*& list, const _Type& value)
            {
                // create a node
                linkedlist<_Type>* node = new linkedlist<_Type>();
                node->m_value = value;
                node->next = nullptr;

                // if list is null -> return node
                if (list == nullptr)
                {
                    list = node;
                    return;
                }

                // find the last node for adding
                linkedlist<_Type>* llist = list;
                while (llist -> next != nullptr)
                {
                    llist = llist->next;
                }
                llist->next = node;
            }


        private:
            linkedlist<int>* m_intLinkedList;
            linkedlist<float>* m_floatLinkedList;
            linkedlist<double>* m_doubleLinkedList;
            linkedlist<string>* m_stringLinkedList;
            
    };


};



#endif