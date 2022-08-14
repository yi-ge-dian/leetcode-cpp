/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;
        int leftBorder = -1;
        int rightBorder = -1;
        leftBorder = getFirstPosition(nums, target);
        rightBorder = getLastPosition(nums, target);
        if (leftBorder == -1 || rightBorder == -1)
            return { -1, -1 };

        return {leftBorder, rightBorder};
    }

    int getFirstPosition(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                if (mid == 0 || nums[mid - 1] != nums[mid])
                {
                    return mid;
                }
                high = mid - 1;
            }
        }
        return -1;
    }

    int getLastPosition(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                if (mid == nums.size() - 1 || nums[mid + 1] != nums[mid])
                {
                    return mid;
                }
                low = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end
