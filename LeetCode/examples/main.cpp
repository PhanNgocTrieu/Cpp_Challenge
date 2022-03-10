#include "leetCode.h"

int main()
{
    leetcode::LeetCodeProblems problems;
    std::vector<int> nums1 = {1,2,3,6};
    std::vector<int> nums2 = {4,5};
    std::cout << problems.findMedianSortedArrays(nums1, nums2) << std::endl;
    std::cout << problems.findMedianSortedArrays(vector<int>() = {
        1,2,
        }, 
        vector<int>() = {
        3,4
    }) << std::endl;
    
    return 0;
}