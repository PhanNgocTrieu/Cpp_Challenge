#ifndef __DTST_H__
#define __DTST_H__

#include "linkedlist.h"
#include "BST.h"
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
            void moveNode(linkedlist<int>*& dest, linkedlist<int>*& src);


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


    class BST_Problems
    {
        public:

            /**
             * @brief   Problem from leet code
             * 
             *          Given the root node of a binary search tree and two integers low and high, 
             *          return the sum of values of all nodes with a value in the inclusive range [low, high].
             * 
             * @param root pointer to the BST
             * @param low below limit of range
             * @param high above limit of range
             * @return int sum of all values of BST which is in range
             */
            int rangeSumBST(DTST_BST::BST<int>* root, int low, int high) {

                if (!root)
                 return 0;
        
                int _sum = 0;
                
                // checking left
                if (root->_value >= low && root->_value <= high)
                {
                    _sum += root->_value;
                }

                if (root->left != nullptr)
                    _sum += rangeSumBST(root->left, low, high);
                if (root->right != nullptr)
                    _sum += rangeSumBST(root->right, low, high);
                
                return _sum;
            }


        /**
         * @brief   Problem from LeetCode
         * 
         *          Given the root of a Binary Search Tree (BST), 
         *          return the minimum absolute difference between the values of any two different nodes in the tree.
         * 
         * @param root 
         * @return int 
        //  */
        // int getMinimumDifference(DTST_BST::BST* root) {
            
        // }


        public:
            // BST_Problems() {
            //     isGetBST = false;
            // }

            void print()
            {
                if (m_BST)
                    DTST_BST::inOrderTravel(m_BST);
            }
        
        private:
            DTST_BST::BST<int>* m_BST;

    };

};



#endif