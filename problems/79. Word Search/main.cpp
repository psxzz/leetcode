#include <bits/stdc++.h>

#include <functional>
#include <utility>

using std::string;
using std::vector;

using board_t = vector<vector<char>>;

class Solution {
	bool dfs(board_t& board, string& word, int r, int c, int word_pos) {
		if (word_pos == word.length()) return true;

		if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() ||
			word[word_pos] != board[r][c])
			return false;

		char prev = board[r][c];
		board[r][c] = '#';
		bool res = dfs(board, word, r + 1, c, word_pos + 1) ||
				   dfs(board, word, r - 1, c, word_pos + 1) ||
				   dfs(board, word, r, c + 1, word_pos + 1) ||
				   dfs(board, word, r, c - 1, word_pos + 1);
		board[r][c] = prev;

		return res;
	};

  public:
	bool exist(board_t& board, string word) {
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				if (dfs(board, word, i, j, 0)) return true;
			}
		}

		return false;
	}
};

int main() {
	Solution s;

	board_t b1 = {
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'},
	};

	std::cout << std::boolalpha << s.exist(b1, "ABCCED") << std::endl;
	std::cout << std::boolalpha << s.exist(b1, "SEE") << std::endl;
	std::cout << std::boolalpha << s.exist(b1, "ABCB") << std::endl;

	return 0;
}