/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] <= 0 && nums[i] > maxSum)        // 若起始位置元素为负数的情况
                maxSum = nums[i];
            else if (nums[i] < 0)
                continue;
            int sum = 0;
            for (int j = i; j != nums.size(); ++j) {
                sum +=nums[j];
                if (sum > maxSum)
                    maxSum = sum;
            }
        }
        return maxSum;
    }
};
