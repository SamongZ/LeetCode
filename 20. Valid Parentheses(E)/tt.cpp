/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        map<char, char> ref = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> brackets;
        for (int i = 0; i != s.length(); ++i) {
            if (brackets.empty())
                brackets.push(s[i]);
            else {
                if (s[i] == ref[brackets.top()])
                    brackets.pop();
                else
                    brackets.push(s[i]);
            }
        }
        return (brackets.empty()) ? true : false;
    }
};
int main()
{
    string s = "{[{]()}";
    Solution fun;
    cout << fun.isValid(s) << endl;
    return 0;
}
