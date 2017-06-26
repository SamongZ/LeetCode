/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int left = 0;
        int right = nums.size() - 1;
        if (target == nums[left]) return left;
        if (target == nums[right]) return right;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (target == nums[mid]) return mid;
            if (nums[left] < nums[mid]) {
                if (target < nums[left] || target > nums[mid])
                    left = mid;
                else
                    right = mid;
            }
            else {
                if (target < nums[mid] || target > nums[left])
                    right = mid;
                else
                    left = mid;
            }
        }
        return -1;
    }
};
