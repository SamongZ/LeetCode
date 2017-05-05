/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        stack<int> nums;
        vector<int> result;
        nums.push((digits[len - 1] + 1) % 10);
        int extra = (digits[len - 1] + 1) / 10;
        for (int i = len - 2; i >= 0; --i) {
            nums.push((digits[i] + extra) % 10);
            extra = (digits[i] + extra) / 10;
        }
        if (extra)
            nums.push(extra);
        while (!nums.empty()) {
            result.push_back(nums.top());
            nums.pop();
        }
        return result;
    }
};
