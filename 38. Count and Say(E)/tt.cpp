/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string pre = countAndSay(n - 1);
        int cnt = 1;
        string curr;
        for (int i = 1; i != pre.size(); ++i) {
            if (pre[i] == pre[i - 1])
                ++cnt;
            else {
                curr += (cnt + '0');
                curr += pre[i - 1];
                cnt = 1;
            }
        }
        curr += (cnt + '0');
        curr += pre[pre.size() - 1];
        return curr;
    }
};
