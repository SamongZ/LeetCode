/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

class Solution1 {
public:
    bool isHappy(int n) {
        if (n <= 0) return false;
        int sum = 0;
        for (int i = 0; i < 100; ++i) {
            sum = 0;
            while (n) {
                int digit = n % 10;
                sum += digit * digit;
                n = n / 10;
            }
            if (sum == 1) return true;
            n = sum;
        }
        return false;
    }
};

class Solution2 {
public:
    bool isHappy(int n) {
        if (n <= 0) return false;
        int slow = sumOfDigits(n);
        int fast = sumOfDigits(sumOfDigits(n));
        while (slow != fast) {
            slow = sumOfDigits(slow);
            fast = sumOfDigits(sumOfDigits(fast));
        }
        if (slow == 1) return true;
        else return false;
    }
private:
    int sumOfDigits(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit *digit;
            n = n / 10;
        }
        return sum;
    }
};
