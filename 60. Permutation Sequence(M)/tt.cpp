/*
The set [1,2,3,��,n] contains a total of n! unique permutations.

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
        vector<int> vec;          // ���ڴ������1��n
        int totalOfpermutations = 1;
        for (int i = 1; i <= n; ++i) {
            vec.push_back(i);
            totalOfpermutations *= i;
        }
        int numsOfgroup = totalOfpermutations / n;     // ���������зֳ�n���飬����ͷΪ1��Ϊһ�飬��ͷΪ2��Ϊһ��ȵ�
        string result;
        while (n > 1) {
            int indexOfgroup = k / numsOfgroup;    // ȷ����ǰλ��Ӧ���ڵڼ���
            k = k % numsOfgroup;
            numsOfgroup = numsOfgroup / (--n);
            if (k == 0) {                                    // k = 0ʱ����Ϊ��������һ������
                result += (vec[indexOfgroup - 1] + '0');
                vec.erase(vec.begin() + indexOfgroup - 1);   // ��vec��ɾ����ʹ�õ�����
                k = n * numsOfgroup;
            }
            else {
                result += (vec[indexOfgroup] + '0');
                vec.erase(vec.begin() + indexOfgroup);
            }
        }
        result += (vec[0] + '0');       // ����vec�����һ������
        return result;
    }
};
