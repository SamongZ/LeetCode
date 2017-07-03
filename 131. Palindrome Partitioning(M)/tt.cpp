/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.size() == 0) return {{}};
        vector<vector<string>> preResult = partition(s.substr(0, s.size() - 1));
        vector<vector<string>> result = preResult;
        for (int i = 0; i < result.size(); ++i)
            result[i].push_back(s.substr(s.size() - 1));
        for (int j = 0; j < s.size() - 1; ++j) {
            if (s[j] == s[s.size() - 1]) {
                int beg = j;
                int end = s.size() - 1;
                while (beg <= end && s[++beg] == s[--end]) { }
                if (end - beg < 1) {
                    preResult = partition(s.substr(0, j));
                    for (int k = 0; k < preResult.size(); ++k) {
                        preResult[k].push_back(s.substr(j));
                    }
                    result.insert(result.end(), preResult.begin(), preResult.end());
                }
            }
        }
        return result;
    }
};
