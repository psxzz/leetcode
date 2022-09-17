#include <bits/stdc++.h>

using std::vector;
using triangle_t = vector<vector<int>>;

class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        triangle_t t;
        t.push_back({1});
        if (numRows == 1) return t;
        t.push_back({1, 1});

        for (int i = 2; i < numRows; ++i) {
            t.push_back(std::vector<int>(i + 1, 1));
            for (int j = 1; j < i; ++j) {
                t[i][j] = t[i - 1][j] + t[i - 1][j - 1];
            }
        }

        return t;
    }
};

int main() {
    Solution s;

    s.generate(5);

    return 0;
}