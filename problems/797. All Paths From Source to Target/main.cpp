#include <bits/stdc++.h>

using std::vector;
using graph_t = vector<vector<int>>;

class Solution {
	void dfs(graph_t &g, vector<vector<int>> &res, vector<int> &p, int u) {
		p.push_back(u);
		if (u == g.size() - 1)
			res.push_back(p);
		else {
			for (auto &v : g[u]) dfs(g, res, p, v);
		}
		p.pop_back();
	}

  public:
	vector<vector<int>> allPathsSourceTarget(graph_t &graph) {
		vector<vector<int>> res;
		vector<int>			path;
		dfs(graph, res, path, 0);
		return res;
	}
};

int main() {
	Solution s;

	graph_t g1 = {
		{1, 2},
		{3},
		{3},
		{},
	};
	graph_t g2 = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};

	auto res = s.allPathsSourceTarget(g1);
	auto res2 = s.allPathsSourceTarget(g2);

	return 0;
}