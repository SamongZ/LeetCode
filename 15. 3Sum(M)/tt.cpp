/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?

Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i) {
            int target = -nums[i];
            int beg = i + 1;
            int end = nums.size() - 1;
            while (beg < end) {
                if (nums[beg] + nums[end] == target) {
                    result.push_back(vector<int>{nums[i], nums[beg], nums[end]});
                    while (nums[beg] == nums[beg + 1]) ++beg;
                    while (nums[end] == nums[end - 1]) --end;
                    ++beg;
                    --end;
                }
                else if (nums[beg] + nums[end] < target)
                    ++beg;
                else if (nums[beg] + nums[end] > target)
                    --end;
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        }
        return result;
    }
};
