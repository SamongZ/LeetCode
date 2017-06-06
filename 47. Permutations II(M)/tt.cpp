/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
            return vector<vector<int>>{nums};
        vector<vector<int>> result;
        set<int> used;
        for (int i = 0; i < len; ++i) {
            if (used.insert(nums[i]).second) {     // Ignore duplicate numbers
                vector<int> preNums(nums);
                preNums.erase(preNums.begin() + i);
                vector<vector<int>> preResult = permuteUnique(preNums);
                for (int j = 0; j < preResult.size(); ++j) {
                    preResult[j].insert(preResult[j].begin(), nums[i]);
                    result.push_back(preResult[j]);
                }
            }
        }
        return result;
    }
};
