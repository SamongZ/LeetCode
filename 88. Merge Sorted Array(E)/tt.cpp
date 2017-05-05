#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>::iterator iter1 = nums1.begin();
        vector<int>::iterator iter2 = nums2.begin();
        while (iter1 != nums1.end()) {
            while (iter2 != nums2.end() && *iter2 <= *iter1) {
                iter1 = nums1.insert(iter1, *iter2);
                ++iter2;
            }
            ++iter1;
        }
        if (iter2 != nums2.end())
            nums1.insert(iter1, iter2, nums2.end());
    }
};
int main()
{
    vector<int> nums1 = {1,2,3,4};
    vector<int> nums2 = {0,0,4,5};
    Solution fun;
    fun.merge(nums1, nums1.size(), nums2, nums2.size());
    for (auto c : nums1)
        cout << c << endl;
    return 0;
}
