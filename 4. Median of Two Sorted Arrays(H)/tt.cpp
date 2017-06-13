/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        if (n == 0) return 0.0;
        if (m == 0) {
            if (n % 2 == 1)
                return nums2[n / 2];
            else
                return (nums2[n / 2] + nums2[n / 2 - 1]) / 2.0;
        }
        int i = 0;
        int j = (m + n + 1) / 2 - i;
        while  (i <= m) {
            if (nums2[j - 1] > nums1[i] && i < m) {
                ++i;
                --j;
            }
            else if (nums1[i - 1] > nums2[j] && i > 0) {
                --i;
                ++j;
            }
            else {
                int maxLeft, minRight;
                if (i == 0) maxLeft = nums2[j - 1];
                else if (j == 0) maxLeft = nums1[i - 1];
                else maxLeft = max(nums1[i - 1], nums2[j - 1]);

                if ((m + n) % 2 == 1)
                    return maxLeft;

                if (i == m) minRight = nums2[j];
                else if (j == n) minRight = nums1[i];
                else minRight = min(nums1[i], nums2[j]);
                return (maxLeft + minRight) / 2.0;
            }
        }
    }
};
