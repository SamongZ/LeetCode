/*
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array,

and it should return false if every element is distinct.
*/


class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 0) return false;
        set<int> si;
        for (int i = 0; i < nums.size(); ++i)
            if (!((si.insert(nums[i])).second)) return true;
        return false;
    }
};

class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 0) return false;
        set<int> si(nums.begin(), nums.end());
        if (si.size() == nums.size()) return false;
        else return true;
    }
};
