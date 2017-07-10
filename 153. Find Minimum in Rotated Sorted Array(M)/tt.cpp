/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution1 {
public:
    int findMin(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1])
                return nums[i];
        }
        return nums[0];
    }
};

class Solution2 {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int left = 0 , right = nums.size() - 1;
        while (nums[left] >= nums[right]) {
            if (right - left == 1) return nums[right];
            int mid = (left + right) / 2;
            if (nums[mid] <= nums[right]) right = mid;
            if (nums[mid] >= nums[left]) left = mid;
        }
        return nums[left];
    }
};
