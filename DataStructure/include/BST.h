#ifndef __BST_H
#define __BST_H


#include <vector>
#include <iostream>
#include <stdio.h>
namespace DTST
{
    namespace DTST_BST
    {
        template <class _Typ>
        struct BST
        {
            _Typ _value;
            BST *left;
            BST *right;
        };

        template <class _Typ>
        void insert(BST<_Typ>*& bst, const _Typ& value)
        {
            if (bst == nullptr)
            {
                BST<_Typ> *newNode = new BST<_Typ>();
                newNode->_value = value;
                newNode->left = nullptr;
                newNode->right = nullptr;

                bst = newNode;
                return;
            }

            if(bst->_value == value)
            {
                printf("Already exists!\n");
            }

            if (bst->_value < value)
            {
                insert(bst->right, value);
            }
            else
            {
                insert(bst->left, value);
            }
        }

        template <class _Typ>
        void inOrderTravel(BST<_Typ>* bst)
        {
            if (bst == nullptr)
            {
                return;
            }

            inOrderTravel(bst->left);
            std::cout << bst->_value << " ";
            inOrderTravel(bst->right);
        }

    };
};
#endif
