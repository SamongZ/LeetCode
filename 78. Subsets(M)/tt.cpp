/*
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result{{}};
        if (nums.size() == 0)
            return result;
        vector<int> preNums(nums.begin(), nums.end() - 1);
        vector<vector<int>> preResult = subsets(preNums);
        result = preResult;
        for (int i = 0; i < preResult.size(); ++i)
            preResult[i].push_back(nums[nums.size() - 1]);
        result.insert(result.end(), preResult.begin(), preResult.end());
        return result;
    }
};
