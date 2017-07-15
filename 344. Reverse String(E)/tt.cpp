/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/


class Solution1 {
public:
    string reverseString(string s) {
        stack<char> chs;
        for (int i = 0; i < s.size(); ++i)
            chs.push(s[i]);
        string result;
        while (!chs.empty()) {
            result += chs.top();
            chs.pop();
        }
        return result;
    }
};

class Solution2 {
public:
    string reverseString(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            ++i;
            --j;
        }
        return s;
    }
};
