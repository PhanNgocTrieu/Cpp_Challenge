#ifndef __DTST_H__
#define __DTST_H__

#include <iostream>
using namespace std;

namespace DTST
{
    class LinkedListProblems
    {
        private:
            struct SinglyLinkedListNode
            {
                int m_intValue;
                float m_floatValue;
                double m_doubleValue;
                string m_stringValue;
                uint16_t m_uint16Value;
                uint32_t m_uint32Value;
                SinglyLinkedListNode* nextNode;
            };
            
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
             */
            bool compare_lists(SinglyLinkedListNode* list1, SinglyLinkedListNode* list2);


        private:
            void printLinkedList();

        private:
            SinglyLinkedListNode* m_linkedList;
    };


};



#endif