#include <bits/stdc++.h>

using std::vector;
using grid_t = vector<vector<int>>;

class Solution {
   private:
    bool isClosed(grid_t& g, int r, int c) {
        if (r < 0 || r >= g.size() || c < 0 || c >= g[r].size()) return false;
        if (g[r][c] == 1) return true;
        g[r][c] = 1;

        bool down = isClosed(g, r + 1, c);
        bool right = isClosed(g, r, c + 1);
        bool left = isClosed(g, r, c - 1);
        bool up = isClosed(g, r - 1, c);

        return down && right && up && left;
    }

   public:
    int closedIsland(grid_t& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 0) {
                    bool closed = isClosed(grid, i, j);
                    if (closed) count++;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution s;

    grid_t g1 = {{1, 1, 1, 1, 1, 1, 1, 0},
                 {1, 0, 0, 0, 0, 1, 1, 0},
                 {1, 0, 1, 0, 1, 1, 1, 0},
                 {1, 0, 0, 0, 0, 1, 0, 1},
                 {1, 1, 1, 1, 1, 1, 1, 0}};

    std::cout << s.closedIsland(g1) << std::endl;

    return 0;
}