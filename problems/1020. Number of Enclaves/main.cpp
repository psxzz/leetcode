#include <bits/stdc++.h>

using std::vector;
using grid_t = vector<vector<int>>;

class Solution {
   private:
    bool isEnclave(grid_t& g, int r, int c, int& count) {
        if (r < 0 || r >= g.size() || c < 0 || c >= g[r].size()) return false;
        if (g[r][c] == 0) return true;
        g[r][c] = 0;

        bool down = isEnclave(g, r + 1, c, count);
        bool right = isEnclave(g, r, c + 1, count);
        bool left = isEnclave(g, r, c - 1, count);
        bool up = isEnclave(g, r - 1, c, count);

        if (down && right && up && left) count++;

        return down && right && up && left;
    }

   public:
    int numEnclaves(grid_t& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    int  cells = 0;
                    bool closed = isEnclave(grid, i, j, cells);
                    if (closed) count += cells;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution s;

    grid_t g1 = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
    };

    grid_t g2 = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
    };

    std::cout << s.numEnclaves(g1) << std::endl;
    std::cout << s.numEnclaves(g2) << std::endl;

    return 0;
}