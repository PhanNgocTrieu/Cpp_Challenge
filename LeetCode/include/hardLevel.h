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

    private:
    };
};

#endif // HARD_LEETCODE_H