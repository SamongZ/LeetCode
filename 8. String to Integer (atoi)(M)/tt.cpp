/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge,
please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
You are responsible to gather all the input requirements up front.

Example:
"", "  56", "56tejw", "uy78", "+78", "-78", "++87", "INT_MAX", "INT_MIN", ...
*/

class Solution {
public:
    int myAtoi(string str) {
        if (str.length() == 0) return 0;
        int i = 0;
        while (str[i] == ' ') { ++i; }
        int flag = 1;
        if (str[i] == '+') {
            flag = 1;
            ++i;
        }
        else if (str[i] == '-') {
            flag = -1;
            ++i;
        }
        long long result = 0;
        while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
            int curr  = str[i] - '0';
            result = result * 10 + curr;
            if (result > INT_MAX) {
                result = INT_MAX + 1;
                break;
            }
            ++i;
        }
        if (flag == 1 && result == INT_MAX + 1)
            result = INT_MAX;
        return flag * result;
    }
};
