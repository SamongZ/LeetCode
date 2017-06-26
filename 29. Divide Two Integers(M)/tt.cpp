/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = (dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0) ? 1 : -1;
        long long divid = (dividend > 0) ? dividend : -(long long)dividend;
        long long divis = (divisor > 0) ? divisor : -(long long)divisor;
        int result = 0;
        while (divid >= divis) {
            long long temp = divis;
            long long multiples = 1;
            while ((temp << 1) <= divid) {
                temp = temp << 1;
                multiples = multiples << 1;
            }
            divid -= temp;
            result += multiples;
        }
        return (sign == 1) ? result : -result;
    }
};
