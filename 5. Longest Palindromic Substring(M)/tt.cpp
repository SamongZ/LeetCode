/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        int maxLen = -1;
        int resultBeg = 0;
        for (int i = 0; i < s.length(); ++i) {
            int beg = i - 1, end = i + 1;
            int newLen = 1;
            while (s[end] == s[i] && end < s.length()) {
                ++end;
                ++newLen;
            }
            while (beg >= 0 && end < s.length() && s[beg] == s[end]) {
                --beg;
                ++end;
                newLen += 2;
            }
            if (newLen > maxLen) {
                maxLen = newLen;
                resultBeg = beg + 1;
            }
        }
        return s.substr(resultBeg, maxLen);
    }
};
