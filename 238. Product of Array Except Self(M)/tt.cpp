/*
Given an array of n integers where n > 1, nums,

return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity?

(Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long total = 1;
        for (auto n : nums)
            total *= (n == 0 ? 1 : n);
        vector<int> result(nums.size());
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                result.assign(nums.size(), 0);
                if (total != 0)
                    result[i] = total;
                total = 0;
            }
            else
                result[i] = total / nums[i];
        }
        return result;
    }
};
