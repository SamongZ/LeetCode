/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        addParentheses(result, "", n, 0);
        return result;
    }
private:
    void addParentheses(vector<string> &result, string str, int n, int m) {
        if (n == 0 && m == 0) {
            result.push_back(str);
            return;
        }
        if (n > 0) addParentheses(result, str + '(', n - 1, m + 1);
        if (m > 0) addParentheses(result, str + ')', n, m - 1);
    }
};
