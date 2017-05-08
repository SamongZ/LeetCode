/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code,
print the sequence of gray code. A gray code sequence must begin with 0.
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0)
            return {0};
        vector<int> pre = grayCode(n - 1);
        vector<int> result(pow(2, n), 0);
        for (int i = 0; i != pre.size(); ++i) {
            result[i] = pre[i];
            result[result.size() - 1 - i] = pre[i] + pow(2, n - 1);
        }
        return result;
    }
};
