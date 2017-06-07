/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if (k > n) return result;
        if (k == 0) return {vector<int>()};
        vector<int> vec;
        for (int m = 0; m < n; ++m)
            vec.push_back(m + 1);
        if (k == n) return {vec};
        vector<vector<int>> preResult1 = combine(n - 1, k - 1);
        vector<vector<int>> preResult2 = combine(n - 1, k);
        result = preResult2;
        for (int i = 0; i < preResult1.size(); ++i) {
            preResult1[i].push_back(n);
            result.push_back(preResult1[i]);
        }
        return result;
    }
};
