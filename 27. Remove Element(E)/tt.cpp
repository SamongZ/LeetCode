/*
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if (len == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int i, j;
        for (i = 0; nums[i] != val && i < len; ++i) { }
        for (j = i; nums[j] == val && j < len; ++j) { }
        int n = j - i;
        for (int k = i; k < len - n; ++k) {
            nums[k] = nums[k + n];
        }
        return len - n;
    }
};

class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int n = 0;
        for (int i = 0; i < len; ++i)
            if (nums[i] != val)
                nums[n++] = nums[i];
        return n;
    }
};
