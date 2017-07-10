/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
*/

class Solution {
public:
    string convertToTitle(int n) {
        string colTitle;
        while (n) {
            int temp = n % 26;
            char ch = ((temp == 0) ? 'Z' : temp - 1 +'A');
            colTitle = ch + colTitle;
            n = ((temp == 0) ? n / 26 - 1 : n / 26);
        }
        return colTitle;
    }
};
