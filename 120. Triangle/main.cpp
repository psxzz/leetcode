#include <bits/stdc++.h>

using std::vector;
using triangle_t = vector<vector<int>>;

class Solution {
   public:
    int minimumTotal(triangle_t& triangle) {
        vector<int> dp(triangle.size() + 1, 0);

        for (int row = triangle.size() - 1; row >= 0; --row) {
            for (int col = 0; col < triangle[row].size(); ++col) {
                dp[col] = triangle[row][col] + std::min(dp[col], dp[col + 1]);
            }
        }

        return dp[0];
    }
};

int main() {
    Solution s;

    triangle_t t1 = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3},
    };

    triangle_t t2 = {
        {-1},
        {2, 3},
        {1, -1, -3},
    };

    std::cout << s.minimumTotal(t1) << std::endl;
    std::cout << s.minimumTotal(t2) << std::endl;

    return 0;
}