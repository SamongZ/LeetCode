/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution {
public:
    int reverse(int x) {
        long long num = 0;
        while (x) {
            num = num * 10 + x % 10;
            x = x / 10;
        }
        return (num > INT_MAX || num < INT_MIN) ? 0 : num;
    }
};
