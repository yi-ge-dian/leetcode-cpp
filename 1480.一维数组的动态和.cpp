#include <vector>
/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */

// @lc code=start
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int total = nums.size();
        if (total ==1) {
            return nums;
        }
        for (size_t i = 1; i < nums.size(); i++)
        {
            nums[i] = nums[i]+ nums[i-1];
        }
        return nums;
    }
};
// @lc code=end

