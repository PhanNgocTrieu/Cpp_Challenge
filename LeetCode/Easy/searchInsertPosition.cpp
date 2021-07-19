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

int findPos(vector<int>& nums, int target)
{
    int start = 0;
    int end = nums.size();
    int middle = (start + end) / 2;
    while (!(nums[middle] == target || (nums[middle] > target && nums[middle - 1] < target) || (nums[middle] < target && target < nums[middle + 1]) ))
    {
        middle = (start + end) / 2;

        if (nums[middle] < target)
            start = middle;
        if (nums[middle] > target)
            end = middle;
    }

    if (nums[middle] == target || (nums[middle] > target && nums[middle - 1] < target))
        return middle;
    if (nums[middle] < target && target < nums[middle + 1])
        return middle + 1;
      
    return middle;
}
int searchInsert(vector<int>& nums, int target) {
    if (target <= nums[0])
        return 0;
    int len = nums.size();
    if (target > nums[len - 1])
        return len;
    if (target == nums[len - 1])
    {
        return len - 1;
    }
    return findPos(nums, target);   
}
