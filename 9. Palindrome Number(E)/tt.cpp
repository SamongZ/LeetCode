/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long int num = 0;
        long long int y = x;
        while (x) {
            num = num * 10 + x % 10;
            x = x / 10;
        }
        return y == num;
    }
};
