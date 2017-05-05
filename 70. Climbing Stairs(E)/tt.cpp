/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
*/
#include <iostream>
using namespace std;

class Solution1 {
public:
    int climbStairs(int n) {
        if (n <= 0) return 0;
        if (n <= 2) return n;
        int oneStep = 2;
        int twoStep = 1;
        int sum = 0;
        for (int i = 3; i <= n; ++i) {
            sum = oneStep + twoStep;
            twoStep = oneStep;
            oneStep = sum;
        }
        return sum;
    }
};
class Solution2 {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main()
{
    int n = 44;
    Solution1 fun1;
    Solution2 fun2;
    cout << fun1.climbStairs(n) << endl;
    cout << fun2.climbStairs(n) << endl;
    return 0;
}
