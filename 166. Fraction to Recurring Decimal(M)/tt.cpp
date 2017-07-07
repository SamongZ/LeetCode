/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
*/

class Solution {
public:
    string fractionToDecimal(long numerator, long denominator) {
        string result;
        if (numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0) result += '-';
        numerator = abs(numerator);
        denominator = abs(denominator);
        long inte = numerator / denominator;
        result += to_string(inte);
        if (numerator % denominator == 0) return result;
        result += '.';
        map<int, int> m;
        for (long r = numerator % denominator; r; r %= denominator) {
            if (m.count(r) > 0) {
                result.insert(m[r], 1, '(');
                result += ')';
                break;
            }
            m[r] = result.size();
            r = r * 10;
            result += to_string(r / denominator);
        }
        return result;
    }
};
