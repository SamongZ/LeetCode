/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool flag = true;
        int tailIndex = nums.size() - 1;
        int max = 0;
        int maxJump = 0;
        for (int i = 0; i <= tailIndex; ++i) {
            maxJump = i + nums[i];    // the max position can be reached from current position
            if (maxJump >= tailIndex)
                break;
            if (maxJump > max)
                max = maxJump;      // the max position can be reached form any indexs
            if (nums[i] == 0) {
                if (max <= i) {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
};
