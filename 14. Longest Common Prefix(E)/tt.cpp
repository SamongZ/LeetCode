/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string comm;
        if (strs.size() == 0)
            return comm;
        if (strs[0] == "")
            return strs[0];
        int i = 0, j = 0;
        for (i = 0; i != strs[0].length(); ++i) {
            for (j = 1; j != strs.size(); ++j) {
                if (strs[j][i] != strs[0][i])
                    break;
            }
            if (j != strs.size())
                break;
        }
        comm = strs[0].substr(0, i);
        return comm;
    }
};
