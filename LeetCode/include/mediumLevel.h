#ifndef _MEDIUM_LEETCODE_H_
#define _MEDIUM_LEETCODE_H_

#include "common.h"

namespace leetcode {

    class mediumLevel {
        public:
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
             * @brief Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c]] such that:
             * 0 <= a, b, c < n
             * a, b and c are distinct.
             * nums[a] + nums[b] + nums[c] == 0
             * 
             * @param nums 
             * @return vector<vector<int>> 
             */
            vector<vector<int>> threeSum(vector<int>& nums);


            /**
             * @brief Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
             * 0 <= a, b, c, d < n
             * a, b, c, and d are distinct.
             * nums[a] + nums[b] + nums[c] + nums[d] == target
             * 
             * You may return the answer in any order.
             * 
             * @param nums 
             * @param target 
             * @return vector<vector<int>> 
             */
            vector<vector<int>> fourSum(vector<int>& nums, int target);


            /**
             * @brief Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
             * 
             * @example 
             *          Input: x = 2.00000, n = 10
             *          Output: 1024.00000
             *          
             *          Input: x = 2.10000, n = 3
             *          Output: 9.26100
             * 
             * 
             *          Input: x = 2.00000, n = -2
             *          Output: 0.25000
             *          Explanation: 2-2 = 1/2^2 = 1/4 = 0.25
             * 
             * 
             * @param x 
             * @param n 
             * @return double 
             */
            double myPow(double x, int n); 

            /**
             * @brief Container with Most Water - problem
             * 
             * @param height Array of the height of water
             * @return int Result of the max area
             */
            int maxArea(const vector<int>& height);


            /**
             * @brief Given the head of a linked list, remove the nth node from the end of the list and return its head.
             * 
             * @param head 
             * @param n 
             * @return ListNode* 
             */
            ListNode* removeNthFromEnd(ListNode* head, int n);


            /**
             * @brief   Given an integer array nums of length n and an integer target, 
             *          find three integers in nums such that the sum is closest to target. 
             *          Return the sum of the three integers.
             *          
             *          You may assume that each input would have exactly one solution.
             * 
             * @param nums 
             * @param target 
             * @return int 
             */
            int threeSumClosest(std::vector<int>& nums, int target);

            /**
             * @brief   Given a linked list, swap every two adjacent nodes and return its head. 
             *          You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
             * 
             */
            ListNode* swapPairs(ListNode* head);


            /**
             * @brief 
             * 
             *          Given an integer n, 
             *          return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.
             * 
             * 
             *          Input: n = 1
             *          Output: 1
             *          Explanation: "1" in binary corresponds to the decimal value 1. 
             * 
             *          Input: n = 3
             *          Output: 27
             *          Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
             *          After concatenating them, we have "11011", which corresponds to the decimal value 27.
             * 
             * @param n 
             * @return int 
             */
            int concatenatedBinary(int n);
    };
};

#endif // _MEDIUM_LEETCODE_H_