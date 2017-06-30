/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (len == 0 || s[0] == '0')
            return 0;
        if (len == 1)
            return 1;
        int result = 0;
        int pre1 = 1, pre2 = 1;
        for (int i = 1; i < len; ++i) {
            if (isValid(s[i]) && isValid(s[i - 1], s[i]))
                result = pre1 + pre2;
            if (isValid(s[i]) && !isValid(s[i - 1], s[i]))
                result = pre2;
            if (!isValid(s[i]) && isValid(s[i - 1], s[i]))
                result = pre1;
            if (!isValid(s[i]) && !isValid(s[i - 1], s[i]))
                return 0;
            pre1 = pre2;
            pre2 = result;
        }
        return result;
    }
private:
    bool isValid(const char &a) {
        return a > '0' && a <= '9';
    }
    bool isValid(const char &a, const char &b) {
        return a == '1' || (a == '2' && b < '7');
    }
};
