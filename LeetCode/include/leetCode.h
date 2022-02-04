#ifndef __LEETCODE_H
#define __LEETCODE_H

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
#include <limits.h>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cctype>


using namespace std;

namespace leetcode
{
    typedef enum {
        easy,
        medium,
        hard
    } LevelOfProblems;

    class LeetCodeProblems
    {
        public:
            LeetCodeProblems() {}
            ~LeetCodeProblems() {}
        private:
            void showProblemsWithID();
            void executedProblemsWithID(const uint32_t& _idOfProblems);


        /**
         * **********************************************************************************
         *                       @brief Supporting for the problems                         *
         * **********************************************************************************
         */
        private: /* Struct for supporting these below problems */

            /**
             * @brief A definition of a combination struct
             * 
             */
            struct Combination{
                vector<int> arr;
                int sum;
                int idx;
            };

            /**
             * @brief A definition of a tree
             * 
             */
            struct TreeNode {
                int val;
                TreeNode* left;
                TreeNode* right;
            };





        /**
         * **********************************************************************************
         *                       @brief Problems of Easy Levels                             *
         * **********************************************************************************
         */
        public: 

            /*
                Given two binary strings a and b, return their sum as a binary string.

                Example 1:
                Input: a = "11", b = "1"
                Output: "100"
                Example 2:

                Input: a = "1010", b = "1011"
                Output: "10101"
                
            */
            string addBinary(string a, string b);

            /**
             * Write a function to find the longest common prefix string amongst an array of strings.
             * 
             * If there is no common prefix, return an empty string "".
             * 
             * Example 1:
             * 
             * Input: strs = ["flower", "flow", "flight"]
             * Output : "fl"
             * 
             * Example 2 :
             * 
             * Input : strs = ["dog", "racecar", "car"]
             * Output : ""
             * 
             * Explanation : There is no common prefix among the input strings.
            */
            string longestCommonPrefix(vector<string>& strs);



            /*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

            You may assume that each input would have exactly one solution, and you may not use the same element twice.

            You can return the answer in any order.

            Example 1:

            Input: nums = [2, 7, 11, 15], target = 9
            Output : [0, 1]
            Because nums[0] + nums[1] == 9, we return[0, 1].

            */
            vector<int> twoSum(vector<int>& nums, int target);



            /*
                Implement strStr().

                Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

                Clarification:

                What should we return when needle is an empty string ? This is a great question to ask during an interview.

                For the purpose of this problem, we will return 0 when needle is an empty string.This is consistent to C's strstr() and Java's indexOf().



                Example 1:

                Input: haystack = "hello", needle = "ll"
                Output : 2
                Example 2 :

                    Input : haystack = "aaaaa", needle = "bba"
                    Output : -1
                    Example 3 :

                    Input : haystack = "", needle = ""
                Output :0
            
            */

            int strStr(string haystack, string needle);



            /*

                Given the root of a binary tree, return the postorder traversal of its nodes' values.

                Input: root = [1,null,2,3]
                Output: [3,2,1]
                Example 2:

                Input: root = []
                Output: []
                Example 3:

                Input: root = [1]
                Output: [1]

            */
            vector<int> postorderTraversal(TreeNode* root);

            /*
                Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

                Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

                Clarification:

                Confused why the returned value is an integer but your answer is an array?

                Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller as well.

                Internally you can think of this:

                // nums is passed in by reference. (i.e., without making a copy)
                int len = removeDuplicates(nums);

                // any modification to nums in your function would be known by the caller.
                // using the length returned by your function, it prints the first len elements.
                for (int i = 0; i < len; i++) {
                    print(nums[i]);
                }


                Example 1:

                Input: nums = [1,1,2]
                Output: 2, nums = [1,2]
                Explanation: Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. 
                It doesn't matter what you leave beyond the returned length.
                Example 2:

                Input: nums = [0,0,1,1,1,2,2,3,3,4]
                Output: 5, nums = [0,1,2,3,4]
                Explanation: Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
                It doesn't matter what values are set beyond the returned length.
            */
            int removeDuplicates(vector<int>& nums);

            /*
                Given a sorted array of distinct integers and a target value,
                return the index if the target is found. If not,
                return the index where it would be if it were inserted in order.
                You must write an algorithm with O(log n) runtime complexity.

                Example 1:
                Input: nums = [1,3,5,6], target = 5
                Output: 2
                Example 2:

                Input: nums = [1,3,5,6], target = 2
                Output: 1
                Example 3:

                Input: nums = [1,3,5,6], target = 7
                Output: 4
                Example 4:

                Input: nums = [1,3,5,6], target = 0
                Output: 0
                Example 5:

                Input: nums = [1], target = 0
                Output: 0
            */

            int findPos(vector<int>& nums, int target);
            int searchInsert(vector<int>& nums, int target);



            /*
                Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

                You must implement a solution with a linear runtime complexity and use only constant extra space.

                

                Example 1:

                Input: nums = [2,2,1]
                Output: 1
                Example 2:

                Input: nums = [4,1,2,1,2]
                Output: 4
                Example 3:

                Input: nums = [1]
                Output: 1
            */

            int singleNumber(vector<int>& nums);





        /**
         * **********************************************************************************
         *                       @brief Problems of Medium Levels                           *
         * **********************************************************************************
         */
        public: 

            /*
                Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

                An input string is valid if:

                Open brackets must be closed by the same type of brackets.
                Open brackets must be closed in the correct order.


                Example 1:

                Input: s = "()"
                Output : true
                Example 2 :

                    Input : s = "()[]{}"
                    Output : true
                    Example 3 :

                    Input : s = "(]"
                    Output : false
                    Example 4 :

                    Input : s = "([)]"
                    Output : false
                    Example 5 :

                    Input : s = "{[]}"
                    Output : true
            */
            bool isValid(string s);




            /*
            Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

            The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

            It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

            Example 1:

            Input: candidates = [2,3,6,7], target = 7
            Output: [[2,2,3],[7]]
            Explanation:
            2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
            7 is a candidate, and 7 = 7.
            These are the only two combinations.
            Example 2:

            Input: candidates = [2,3,5], target = 8
            Output: [[2,2,2,2],[2,3,3],[3,5]]
            Example 3:

            Input: candidates = [2], target = 1
            Output: []
            Example 4:

            Input: candidates = [1], target = 1
            Output: [[1]]
            Example 5:

            Input: candidates = [1], target = 2
            Output: [[1,1]]
            */

            // using stack - we can use queue (but we have to implement it!)
            vector<vector<int>> combinationSum(vector<int>& candidates, int target);




            /*
                Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

                Symbol       Value
                I             1
                V             5
                X             10
                L             50
                C             100
                D             500
                M             1000
                For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

                Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

                I can be placed before V (5) and X (10) to make 4 and 9. 
                X can be placed before L (50) and C (100) to make 40 and 90. 
                C can be placed before D (500) and M (1000) to make 400 and 900.
                Given an integer, convert it to a roman numeral.    

                Example 1:

                Input: num = 3
                Output: "III"
                Example 2:

                Input: num = 4
                Output: "IV"
                Example 3:

                Input: num = 9
                Output: "IX"
                Example 4:

                Input: num = 58
                Output: "LVIII"
                Explanation: L = 50, V = 5, III = 3.
                Example 5:

                Input: num = 1994
                Output: "MCMXCIV"
                Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
            */
            string intToRoman(int num);


            /*
                Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

                The algorithm for myAtoi(string s) is as follows:

                Read in and ignore any leading whitespace.
                Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
                Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
                Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
                If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
                Return the integer as the final result.
                Note:

                Only the space character ' ' is considered a whitespace character.
                Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
            */
            // First way:
            int myAtoi(string s);


            /*
                Given a string s, return the longest palindromic substring in s.
                Example 1:
                Input: s = "babad"
                Output: "bab"
                Note: "aba" is also a valid answer.
                Example 2:
                Input: s = "cbbd"
                Output: "bb"

            */
            int pallindromeLength(int &l, int &r, string &s);
            string longestPalindrome(string s);

            /**
             * @brief 
             * 
             *  Given a string s, find the length of the longest substring without repeating characters.
             *  Input: s = "abcabcbb"
             *  Output: 3
             *  Explanation: The answer is "abc", with the length of 3.
        
             * @param s 
             * @return int 
             */
            int lengthOfLongestSubstring(string s);

            /**
             * @brief 
             *      Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
             *      
             *      Input: nums = [0,1]
             *      Output: 2 
             *      Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.     
             *  
             *      Input: nums = [0,1,0]
             *      Output: 2
             *      Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
             * 
             * @param nums 
             * @return int 
             */
            int findMaxLength(vector<int>& nums);

        /**
         * **********************************************************************************
         *                       @brief Problems of Hard Levels                             *
         * **********************************************************************************
         */
        public: 

            /**
             * @brief 
             *      Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
             *      The overall run time complexity should be O(log (m+n)).
             * 
             * @param nums1 
             * @param nums2 
             * @return double 
             */
            double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

        private:
            map<LevelOfProblems, uint32_t> m_tableOfProblems;
    };
};

#endif


