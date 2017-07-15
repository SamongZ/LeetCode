/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> backet(nums.size() + 1, false);
        for (int i = 0; i < nums.size(); ++i)
            backet[nums[i]] = true;
        for (int j = 0; j < backet.size(); ++j)
            if (backet[j] == false)
                return j;
    }
};

class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        int result = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            result ^= i;
            result ^= nums[i];
        }
        return result;
    }
};
