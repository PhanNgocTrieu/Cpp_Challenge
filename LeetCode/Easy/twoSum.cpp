/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2, 7, 11, 15], target = 9
Output : [0, 1]
Because nums[0] + nums[1] == 9, we return[0, 1].

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;

    int len = nums.size();
	
	for (int index = 0; index < len; index++)
	{
		// target = num_1 + num_2 => num_2 = target - num_1
        int num_2 = target - nums[index];
        int start = index + 1;
		while (start < len)
		{
			if (nums[start] == num_2)
			{
                res.push_back(index);
                res.push_back(start);
                return  res;
			}
            start++;
		}
	}
    return res;
}
