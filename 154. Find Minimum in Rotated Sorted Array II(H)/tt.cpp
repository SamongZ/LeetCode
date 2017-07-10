/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int left = 0 , right = nums.size() - 1;
        while (nums[left] >= nums[right]) {
            if (right - left == 1) return nums[right];
            int mid = (left + right) / 2;
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                int min = nums[left];
                for (int i = left; i <= right; ++i)
                    if (nums[i] < min) min = nums[i];
                return min;
            }
            if (nums[mid] <= nums[right]) right = mid;
            if (nums[mid] >= nums[left]) left = mid;
        }
        return nums[left];
    }
};
