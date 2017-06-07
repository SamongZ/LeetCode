/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/

// use loop
class Solution1 {
public:
    int addDigits(int num) {
        while (num / 10 != 0) {
            int sum = 0;
            while (num != 0) {
                sum += num % 10;
                num = num / 10;
            }
            num = sum;
        }
        return num;
    }
};
// O(1) use digit-root
// For base b (decimal case b = 10), the digit root of an integer is:

// dr(n) = 0 if n == 0
// dr(n) = (b-1) if n != 0 and n % (b-1) == 0
// dr(n) = n mod (b-1) if n % (b-1) != 0
class Solution2 {
public:
    int addDigits(int num) {
        int result = num % 9;
        return ((result != 0 || num == 0) ? result : 9);
    }
};
