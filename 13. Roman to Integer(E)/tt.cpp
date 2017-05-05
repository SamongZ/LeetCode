/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution1 {
public:
    int romanToInt(string s) {
        stack<int> nums;
        for (int i = 0; i != s.length(); ++i) {
            if (s[i] == 'I')
                nums.push(1);
            if (s[i] == 'V')
                nums.push(5);
            if (s[i] == 'X')
                nums.push(10);
            if (s[i] == 'L')
                nums.push(50);
            if (s[i] == 'C')
                nums.push(100);
            if (s[i] == 'D')
                nums.push(500);
            if (s[i] == 'M')
                nums.push(1000);
        }
        int pre = 0;
        int sum = 0;
        while (!nums.empty()) {
            if (nums.top() >= pre)
                sum += nums.top();
            else
                sum -= nums.top();
            pre = nums.top();
            nums.pop();
        }
        return sum;
    }
};
class Solution2 {
public:
    int romanToInt(string s) {
        vector<int> nums;
        for (int i = 0; i != s.length(); ++i) {
            if (s[i] == 'I')
                nums.push_back(1);
            if (s[i] == 'V')
                nums.push_back(5);
            if (s[i] == 'X')
                nums.push_back(10);
            if (s[i] == 'L')
                nums.push_back(50);
            if (s[i] == 'C')
                nums.push_back(100);
            if (s[i] == 'D')
                nums.push_back(500);
            if (s[i] == 'M')
                nums.push_back(1000);
        }
        for (int j = 0; j != nums.size() - 1; ++j) {
            if (nums[j] < nums[j + 1])
                nums[j] = -nums[j];
        }
        int sum = 0;
        for (auto c : nums)
            sum += c;
        return sum;
    }
};
