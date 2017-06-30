/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
",." is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 0) return true;
        int beg = 0;
        int end = s.length() - 1;
        while (beg < end) {
            if (!valid(s[beg])) {
                ++beg;
                continue;
            }
            if (!valid(s[end])) {
                --end;
                continue;
            }
            if (change(s[beg]) != change(s[end]))
                return false;
            ++beg;
            --end;
        }
        return true;
    }
private:
    bool valid(const char &ch) {
        return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
    char change(char ch) {
        if (ch >= 'A' && ch <= 'Z') ch += 32;
        return ch;
    }
};
