#include <bits/stdc++.h>

using std::vector;
using grid_t = vector<vector<int>>;

class Solution {
   public:
    int orangesRotting(grid_t& grid) {
        std::queue<std::pair<int, int>> q;
        int time = 0;
        int fresh = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[row].size(); ++col) {
                if (grid[row][col] == 1) fresh++;

                if (grid[row][col] == 2) q.push(std::make_pair(row, col));
            }
        }

        while (!q.empty() && fresh > 0) {
            int qSize = q.size();

            for (int i = 0; i < qSize; ++i) {
                std::pair<int, int> f = q.front();
                int r = f.first;
                int c = f.second;
                q.pop();
                int up = r - 1, down = r + 1, left = c - 1, right = c + 1;
                if (up >= 0 && grid[up][c] == 1) {
                    grid[up][c] = 2;
                    q.push(std::make_pair(up, c));
                    fresh--;
                }

                if (down < grid.size() && grid[down][c] == 1) {
                    grid[down][c] = 2;
                    q.push(std::make_pair(down, c));
                    fresh--;
                }

                if (left >= 0 && grid[r][left] == 1) {
                    grid[r][left] = 2;
                    q.push(std::make_pair(r, left));
                    fresh--;
                }

                if (right < grid[r].size() && grid[r][right] == 1) {
                    grid[r][right] = 2;
                    q.push(std::make_pair(r, right));
                    fresh--;
                }
            }

            time++;
        }

        return !fresh ? time : -1;
    }
};

int main() {
    Solution s;

    grid_t g1 = {
        {2, 1, 1},
        {1, 1, 0},
        {1, 0, 1},
    };

    std::cout << s.orangesRotting(g1) << std::endl;

    return 0;
}