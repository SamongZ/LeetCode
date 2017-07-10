/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vec(nums.size());
        string result;
        for (int i = 0; i < nums.size(); ++i)
            vec[i] = to_string(nums[i]);
        sort(vec.begin(), vec.end(), [](string &s1, string &s2){ return s1 + s2 > s2 + s1; });
        for (int j = 0; j < vec.size(); ++j)
            result += vec[j];
        while (result[0] == '0' && result.length() > 1)
            result.erase(0,1);
        return result;
    }
};
