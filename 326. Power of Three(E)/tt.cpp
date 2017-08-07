/*
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/

class Solution1 {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n) / log10(3), 1) == 0;
    }
};

class Solution2 {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        long temp = 1;
        while (temp < n)
            temp *= 3;
        if (temp == n) return true;
        else return false;
    }
};
