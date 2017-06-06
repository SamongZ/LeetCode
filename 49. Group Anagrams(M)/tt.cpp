/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<multiset<char>, vector<string>> mmv;
        for (auto str : strs) {
            multiset<char> charOfStr(str.begin(), str.end());
            mmv[charOfStr].push_back(str);
        }
        vector<vector<string>> result;
        for (auto m : mmv)
            result.push_back(m.second);
        return result;
    }
};
