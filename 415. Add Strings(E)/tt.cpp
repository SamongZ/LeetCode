/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        if (len1 == 0) return num2;
        if (len2 == 0) return num1;
        int extra = 0;
        string result;
        for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0 || extra; --i, --j) {
            int curr1 = (i < 0) ? 0 : num1[i] - '0';
            int curr2 = (j < 0) ? 0 : num2[j] - '0';
            int curr = (curr1 + curr2 + extra) % 10;
            extra = (curr1 + curr2 + extra) / 10;
            char currChar = curr + '0';
            result = currChar + result;
        }
        return result;
    }
};
