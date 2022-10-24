#include <bits/stdc++.h>

using std::vector;
using grid_t = vector<vector<char>>;

class Solution {
	void eraseIsland(grid_t &grid, int r, int c) {
		grid[r][c] = 0;
		int down = r + 1, up = r - 1, left = c - 1, right = c + 1;
		if (down < grid.size() && grid[down][c] == '1')
			eraseIsland(grid, down, c);
		if (up >= 0 && grid[up][c] == '1') eraseIsland(grid, up, c);
		if (right < grid[r].size() && grid[r][right] == '1')
			eraseIsland(grid, r, right);
		if (left >= 0 && grid[r][left] == '1') eraseIsland(grid, r, left);
	}

  public:
	int numIslands(grid_t &grid) {
		int counter = 0;
		for (int row = 0; row < grid.size(); ++row) {
			for (int col = 0; col < grid[row].size(); ++col) {
				if (grid[row][col] == '1') {
					counter++;
					eraseIsland(grid, row, col);
				}
			}
		}

		return counter;
	}
};

int main() {
	Solution s;

	grid_t g1 = {
		{'1', '1', '1', '1', '0'},
		{'1', '1', '0', '1', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},
	};
	grid_t g2 = {
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'},
	};

	std::cout << s.numIslands(g1) << std::endl;
	std::cout << s.numIslands(g2) << std::endl;

	return 0;
}