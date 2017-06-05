/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
            return vector<vector<int>>{nums};
        vector<vector<int>> result;
        for (int i = 0; i < len; ++i) {
            vector<int> preNums = nums;
            preNums.erase(preNums.begin() + i);
            vector<vector<int>> preResult = permute(preNums);
            for (int j = 0; j < preResult.size(); ++j) {
                preResult[j].insert(preResult[j].begin(), nums[i]);
                result.push_back(preResult[j]);
            }
        }
        return result;
    }
};
