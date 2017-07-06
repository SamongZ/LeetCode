/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
            ++m[nums[i]];
        for (auto c : m)
            if (c.second == 1)
                return c.first;
    }
};

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); ++i)
            result = result ^ nums[i];
        return result;
    }
};
