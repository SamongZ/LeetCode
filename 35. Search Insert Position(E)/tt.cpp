/*
Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 return 2
[1,3,5,6], 2 return 1
[1,3,5,6], 7 return 4
[1,3,5,6], 0 return 0
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        if (target <= nums[left])
            return 0;
        if (target == nums[right])
            return right;
        if (target > nums[right])
            return len;
        while (right - left != 1) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid;
            else
                left = mid;
        }
        return right;
    }
};
