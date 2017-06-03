/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> vec;          // 用于存放数字1到n
        int totalOfpermutations = 1;
        for (int i = 1; i <= n; ++i) {
            vec.push_back(i);
            totalOfpermutations *= i;
        }
        int numsOfgroup = totalOfpermutations / n;     // 将所有排列分成n个组，即开头为1的为一组，开头为2的为一组等等
        string result;
        while (n > 1) {
            int indexOfgroup = k / numsOfgroup;    // 确定当前位置应该在第几组
            k = k % numsOfgroup;
            numsOfgroup = numsOfgroup / (--n);
            if (k == 0) {                                    // k = 0时，即为该组的最后一个排列
                result += (vec[indexOfgroup - 1] + '0');
                vec.erase(vec.begin() + indexOfgroup - 1);   // 从vec中删除已使用的数字
                k = n * numsOfgroup;
            }
            else {
                result += (vec[indexOfgroup] + '0');
                vec.erase(vec.begin() + indexOfgroup);
            }
        }
        result += (vec[0] + '0');       // 加上vec中最后一个数字
        return result;
    }
};
