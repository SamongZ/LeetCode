/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length();
        int len2 = needle.length();
        if (len1 < len2)
            return -1;
        if (len2 == 0)
            return 0;
        for (int i = 0; i <= len1 - len2; ++i) {
            if (haystack[i] == needle[0]) {
                int j;
                for (j = 1; j < len2 && haystack[i + j] == needle[j]; ++j);
                if (j == len2)
                    return i;
            }
        }
        return -1;
    }
};
