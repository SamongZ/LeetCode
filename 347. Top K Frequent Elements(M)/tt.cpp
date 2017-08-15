/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ? k ? number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> num_times;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i)
            ++num_times[nums[i]];
        vector<vector<int>> buket(nums.size() + 1);
        for (auto iter = num_times.begin(); iter != num_times.end(); ++iter)
            buket[iter -> second].push_back(iter -> first);
        for (int i = buket.size() - 1; i >=0 ; --i) {
            for (int j = 0; j < buket[i].size(); ++j) {
                result.push_back(buket[i][j]);
                if (result.size() == k) return result;
            }
        }
        return result;
    }
};
