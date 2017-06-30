/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        if (numRows == 1) return {{1}};
        vector<vector<int>> result{{1}, {1, 1}};
        vector<int> preVec{1, 1};
        for (int i = 3; i <= numRows; ++i) {
            vector<int> vec(preVec.size() + 1, 1);
            for (int j = 0; j < preVec.size() - 1; ++j)
                vec[j + 1] = preVec[j] + preVec[j + 1];
            result.push_back(vec);
            preVec = vec;
        }
        return result;
    }
};
