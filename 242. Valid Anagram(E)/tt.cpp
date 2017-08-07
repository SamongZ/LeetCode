/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        multiset<char> s_ch, t_ch;
        for (int i = 0; i < s.length(); ++i) {
            s_ch.insert(s[i]);
            t_ch.insert(t[i]);
        }
        return s_ch == t_ch;
    }
};
