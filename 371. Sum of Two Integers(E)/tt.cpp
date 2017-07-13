/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
*/

class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0, extra = 0;
        do {
            sum = a ^ b;
            extra = (a & b) << 1;
            a = sum;
            b = extra;
        } while (b != 0);
        return a;
    }
};
