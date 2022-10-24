#include <bits/stdc++.h>

using std::vector;
using matrix_t = vector<vector<int>>;

class Solution {
	void dfs(matrix_t &isConnected, vector<bool> &visited, int start) {
		visited[start] = true;
		for (int i = 0; i < isConnected.size(); ++i) {
			if (i != start && isConnected[i][start] == 1) {
				if (!visited[i]) dfs(isConnected, visited, i);
			}
		}
	}

  public:
	int findCircleNum(matrix_t &isConnected) {
		vector<bool> visited(isConnected.size(), false);
		int			 res = 0;

		for (int i = 0; i < isConnected.size(); ++i) {
			if (!visited[i]) {
				dfs(isConnected, visited, i);
				res++;
			}
		}

		return res;
	}
};

int main() {
	Solution s;

	matrix_t m1 = {
		{1, 1, 0},
		{1, 1, 0},
		{0, 0, 1},
	};

	matrix_t m2 = {
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1},
	};

	std::cout << s.findCircleNum(m1) << std::endl;
	std::cout << s.findCircleNum(m2) << std::endl;

	return 0;
}