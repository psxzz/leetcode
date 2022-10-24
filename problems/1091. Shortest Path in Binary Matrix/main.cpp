#include <bits/stdc++.h>

using std::vector;

using grid_t = vector<vector<int>>;

class Solution {
  public:
	int shortestPathBinaryMatrix(grid_t &grid) {
		int n = grid.size();
		if (grid[0][0] || grid[n - 1][n - 1]) return -1;

		std::queue<std::tuple<int, int, int>> q;

		std::vector<std::pair<int, int>> dirs = {
			{0, 1}, {0, -1}, {1, 0},  {-1, 0},
			{1, 1}, {1, -1}, {-1, 1}, {-1, -1},
		};

		q.emplace(0, 0, 1);
		grid[0][0] = 1;

		int r, c, len;
		while (!q.empty()) {
			std::tie(r, c, len) = q.front();
			q.pop();

			if (r == n - 1 && c == n - 1) return len;

			int r_inc, c_inc;
			for (auto dir : dirs) {
				std::tie(r_inc, c_inc) = dir;

				int new_r = r + r_inc, new_c = c + c_inc;
				if ((new_r >= 0 && new_r < n) && (new_c >= 0 && new_c < n) &&
					grid[new_r][new_c] == 0) {
					grid[new_r][new_c] = 1;
					q.emplace(new_r, new_c, len + 1);
				}
			}
		}

		return -1;
	}
};

int main() {
	Solution s;

	grid_t g1 = {
		{0, 1},
		{1, 0},
	};

	std::cout << s.shortestPathBinaryMatrix(g1) << std::endl;

	return 0;
}