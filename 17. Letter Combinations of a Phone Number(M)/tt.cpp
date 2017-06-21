/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, vector<char>> dTol{{'1', {}}, {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
                                     {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}}, {'6', {'m', 'n', 'o'}},
                                     {'7', {'p', 'q', 'r', 's'}}, {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}},
                                     {'0', {}}};
        vector<string> result;
        if (digits.length() == 0) return result;
        result.push_back("");
        for (int i = 0; i < digits.length(); ++i) {
            vector<string> temp;
            for (int j = 0; j < dTol[digits[i]].size(); ++j) {
                for (int k = 0; k < result.size(); ++k) {
                    temp.push_back(result[k] + dTol[digits[i]][j]);
                }
            }
            result = temp;
        }
        return result;
    }
};
