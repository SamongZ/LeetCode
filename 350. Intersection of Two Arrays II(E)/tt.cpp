/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> small, large, result;
        map<int, int> m;
        small = nums1.size() < nums2.size() ? nums1 : nums2;
        large = nums1.size() < nums2.size() ? nums2 : nums1;
        for (int i = 0; i < large.size(); ++i)
            ++m[large[i]];
        for (int j = 0; j < small.size(); ++j) {
            if (m[small[j]] != 0) {
                result.push_back(small[j]);
                --m[small[j]];
            }
        }
        return result;
    }
};
