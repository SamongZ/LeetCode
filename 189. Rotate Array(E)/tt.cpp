/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len <= 1) return;
        k = k % len;
        deque<int> dq(nums.begin(), nums.end());
        int temp;
        for (int i = 0; i < k; ++i) {
            temp = dq.back();
            dq.pop_back();
            dq.push_front(temp);
        }
        nums = vector<int>(dq.begin(), dq.end());
    }
};
