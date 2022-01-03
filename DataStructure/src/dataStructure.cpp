#include "dataStructure.h"
#include "linkedlist.h"

namespace DTST
{
    LinkedListProblems::LinkedListProblems() :  m_intLinkedList(nullptr),
                                                m_floatLinkedList(nullptr),
                                                m_doubleLinkedList(nullptr),
                                                m_stringLinkedList(nullptr)
    {
    }

    LinkedListProblems::~LinkedListProblems()
    {
        if (m_intLinkedList != nullptr)
        {
            delete m_intLinkedList;
            m_intLinkedList = nullptr;
        }

        if (m_floatLinkedList != nullptr)
        {
            delete m_floatLinkedList;
            m_floatLinkedList = nullptr;
        }

        if (m_doubleLinkedList != nullptr)
        {
            delete m_doubleLinkedList;
            m_doubleLinkedList = nullptr;
        }

        if (m_stringLinkedList != nullptr)
        {
            delete m_stringLinkedList;
            m_stringLinkedList = nullptr;
        }
    }

    void LinkedListProblems::initializingLinkedList(linkedlist<int>*& list, vector<int> arrOfValue)
    {
        for (auto elems : arrOfValue)
        {
            addingNode(list, elems);
        }
    }



    /**
     * @brief solving compare list
     *      
     * @remark already test -> successful
     */
    bool LinkedListProblems::compare_lists(linkedlist<int>* list1, linkedlist<int>* list2)
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
    linkedlist<int>* LinkedListProblems::reverse(linkedlist<int>*& head)
    {
        linkedlist<int>* pre = nullptr;
        linkedlist<int>* curr = head;
        linkedlist<int>* next = nullptr;
        
        
        while (curr != NULL) {
            next = curr -> next;
            curr -> next = pre;
            pre = curr;
            curr = next;
        }
        
        m_intLinkedList = pre;
        printLinkedList();
        head = pre;
        return pre;
    }

    /**
     * @brief   Merging two sorted linked list
     * 
     * Example: 
     *          list 1: 1->2->4->5->null
     *          list 2: 1->3->6->7->null
     *          merged list: 1->1->2->3->4->5->6->7->null
     *          
     * 
     * @remark 
     */
    linkedlist<int>* LinkedListProblems::mergeLists(linkedlist<int>* head1, linkedlist<int>* head2)
    {
        if (head1 == nullptr)
        {
            return head2;
        }

        if (head2 == nullptr)
        {
            return head1;
        }

        linkedlist<int>* runForList1 = head1;
        linkedlist<int>* runForList2 = head2;
        linkedlist<int>* temp = nullptr;
        linkedlist<int>* res = temp;

        while (runForList1 != nullptr && runForList2 != nullptr)
        {
            printf("line: %d\n",__LINE__);
            linkedlist<int>* node = new linkedlist<int>();
            node->next = nullptr;
            
            if (runForList1->m_value < runForList2->m_value)
            {
                node->m_value = runForList1->m_value;
                runForList1 = runForList1->next;
            }
            else
            {
                node->m_value = runForList2->m_value;
                runForList2 = runForList2->next;
            }

            printf("line: %d\n",__LINE__);
            if (temp == nullptr)
            {
                temp = node;
                res = temp;
            }
            else
            {
                printf("line: %d\n",__LINE__);
                temp->next = node;
            }

            temp = temp->next;
        }

        // printf("line: %d\n",__LINE__);
        // if (runForList1 == nullptr && runForList2 != nullptr)
        // {
        //     printf("line: %d\n",__LINE__);
        //     temp->next = runForList2;
        // }
        // printf("line: %d\n",__LINE__);
        // if (runForList2 == nullptr && runForList1 != nullptr)
        // {
        //     printf("line: %d\n",__LINE__);
        //     temp->next = runForList1;
        // }
        
        

        m_intLinkedList = res;
        printf("line: %d\n",__LINE__);
        printLinkedList();
        printf("line: %d\n",__LINE__);
        m_intLinkedList = nullptr;
        return res;
    }


    linkedlist<int>* LinkedListProblems::deleteNode(linkedlist<int>* llist, int position)
    {
        linkedlist<int>* iRun = llist;
        linkedlist<int>* pre = nullptr;
        int _count = 0;

        while (_count < position && iRun -> next != nullptr)
        {
            pre = iRun;
            iRun = iRun->next;
            _count++;
        }
        
        pre->next = iRun->next;

        m_intLinkedList = llist;
        printLinkedList();
        m_intLinkedList = nullptr;
        return llist;
    }


    /**
     * @brief printing the list of the method
     * 
     */
    void LinkedListProblems::printLinkedList()
    {
        // print the list of integer numbers
        linkedlist<int>* run = nullptr;
        if (m_intLinkedList)
        {
            run = m_intLinkedList;
        }
        
        // print the list of float numbers
        if (m_floatLinkedList)
        {
            run = m_intLinkedList;
        }

        // print the list of double numbers
        if (m_doubleLinkedList)
        {
            run = m_intLinkedList;
        }

        // print the list of strings
        if (m_stringLinkedList)
        {
            run = m_intLinkedList;
        }

        while (run != nullptr)
        {
            cout << run->m_value << " -> ";
            run = run->next;
        }

        cout << endl;        
    }

};