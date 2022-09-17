#include <bits/stdc++.h>

using std::vector;
using grid_t = vector<vector<int>>;

class Solution {
   public:
    int countIsland(grid_t& grid, int r, int c) {
        int count = 1;
        grid[r][c] = 0;
        int right = c + 1, down = r + 1;
        int left = c - 1, up = r - 1;

        if (right < grid[r].size() && grid[r][right] == 1)
            count += countIsland(grid, r, right);

        if (down < grid.size() && grid[down][c] == 1)
            count += countIsland(grid, down, c);

        if (up >= 0 && grid[up][c] == 1)
            count += countIsland(grid, up, c);

        if (left >= 0 && grid[r][left] == 1)
            count += countIsland(grid, r, left);

        return count;
    }

    int maxAreaOfIsland(grid_t& grid) {
        int max = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[row].size(); ++col) {
                if (grid[row][col] == 1) {
                    int islandArea = this->countIsland(grid, row, col);
                    max = std::max(max, islandArea);
                }
            }
        }

        return max;
    }

    void printGrid(grid_t& g) {
        for (auto r : g) {
            for (auto c : r) {
                std::cout << c << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Solution s;

    grid_t g1 = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    s.printGrid(g1);

    std::cout << s.maxAreaOfIsland(g1) << std::endl;

    s.printGrid(g1);

    return 0;
}