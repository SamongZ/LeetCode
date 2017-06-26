/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int left = 0;
        int right = nums.size() - 1;
        if (nums[left] == target) {
            int right = left;
            while (nums[right] == target && right < nums.size()) ++right;
            return {left, right - 1};
        }
        if (nums[right] == target) {
            int left = right;
            while (nums[left] == target && left >= 0) --left;
            return {left + 1, right};
        }
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                left = right = mid;
                while (nums[right] == target && right < nums.size()) ++right;
                while (nums[left] == target && left >= 0) --left;
                return {left + 1, right - 1};
            }
            else if (target > nums[mid])
                left = mid;
            else if (target < nums[mid])
                right = mid;
        }
        return {-1, -1};
    }
};
