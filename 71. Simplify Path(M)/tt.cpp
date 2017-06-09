/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
path = "////c/", => "/c"
path = "/", => "/"
*/

class Solution {
public:
    string simplifyPath(string path) {
        int len = path.length();
        string result;
        if (len == 0) return result;
        vector<string> subDir;
        for (int i = 0; i < len; ++i) {
            if (path[i] == '/') continue;
            int j = i;
            while (j < len && path[j] != '/') ++j;
            string currDir = path.substr(i, j - i);
            if (currDir == "..") {
                if (!subDir.empty())
                    subDir.pop_back();
            }
            else if (currDir != ".")
                subDir.push_back(currDir);
            i = j;
        }
        if (subDir.empty()) return "/";
        for (int k = 0; k < subDir.size(); ++k)
            result += "/" +subDir[k];
        return result;
    }
};
