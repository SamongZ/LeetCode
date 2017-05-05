/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution1 {
public:
    string addBinary(string a, string b) {
        int len1 = a.length();
        int len2 = b.length();
        if (len1 > len2)
            b = string(len1 - len2, '0') + b;
        else
            a = string(len2 - len1, '0') + a;
        int extra = 0;
        stack<int> nums;
        string result;
        for (int i = a.length() - 1; i >= 0; --i) {
            nums.push(((a[i] - '0') + (b[i] - '0') + extra) % 2);
            extra = ((a[i] - '0') + (b[i] - '0') + extra) / 2;
        }
        if (extra)
            nums.push(extra);
        while (!nums.empty()) {
            result += (nums.top() + '0');
            nums.pop();
        }
        return result;
    }
};
class Solution2 {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1;
        int extra = 0;
        string result;
        while (i >= 0 || j >= 0 || extra) {
            int sum = ((i < 0) ? 0 : (a[i] - '0')) + ((j < 0) ? 0 : (b[j] - '0')) + extra;
            char temp = (sum % 2) + '0';
            result = temp + result;
            extra = sum / 2;
            --i;--j;
        }
        return result;
    }
};
int main()
{
    string a = "111", b = "1";
    Solution2 fun;
    cout << fun.addBinary(a, b) << endl;
    return 0;
}
