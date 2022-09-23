#ifndef HARD_LEETCODE_H
#define HARD_LEETCODE_H

#include "common.h"

namespace leetcode
{
    class hardLevel
    {
    public:
        /**
         * **********************************************************************************
         *                       @brief Problems of Hard Levels                             *
         * **********************************************************************************
         */
        /**
         * @brief
         *      Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
         *      The overall run time complexity should be O(log (m+n)).
         *
         * @param nums1
         * @param nums2
         * @return double
         */
        double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2);

        /**
         * @brief
         *
         * @param s
         * @param p
         * @return true
         * @return false
         */
        bool isMatch(string s, string p);

        /**
         * @brief 
         *          You are given an array of k linked-lists lists, each linked-list is sorted
         *          in ascending order. Merge all the linked-lists into one sorted linked-list
         *          and return it.
         * 
         *          Input: lists = [[1,4,5],[1,3,4],[2,6]]
         *          Output: [1,1,2,3,4,4,5,6]
         * 
         *          Explanation: The linked-lists are:
                    [
                        1->4->5,
                        1->3->4,
                        2->6
                    ]
                    merging them into one sorted list:
                    1->1->2->3->4->4->5->6
            * 
            * @param lists 
            * @return ListNode* 
            */
        ListNode* mergeKLists(vector<ListNode*>& lists);

    private:
    };
};

#endif // HARD_LEETCODE_H