/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
*/

class Solution1 {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (nums[j] < nums[i]) {
                    int temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                }
            }
        }
    }
};

class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int beg = 0;
        int end = nums.size() - 1;
        for (int i = 0; i <= end; ++i) {
            while (i <= end && nums[i] == 2) {
                swap(nums[i], nums[end]);
                --end;
            }
            while (i >= beg && nums[i] == 0) {
                swap(nums[i], nums[beg]);
                ++beg;
            }
        }
    }
};
