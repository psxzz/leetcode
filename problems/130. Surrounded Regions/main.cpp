#include <bits/stdc++.h>

using std::vector;

using board_t = vector<vector<char>>;
class Solution {
	void capture(int i, int j, board_t &b) {
		if (i < 0 || j < 0 || i == b.size() || j == b[0].size() ||
			b[i][j] != 'O')
			return;
		b[i][j] = 'P';

		capture(i + 1, j, b);
		capture(i - 1, j, b);
		capture(i, j + 1, b);
		capture(i, j - 1, b);
	}

  public:
	void solve(board_t &board) {
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				if (board[i][j] == 'O' &&
					((i == 0 || i == board.size() - 1) ||
					 (j == 0 || j == board[0].size() - 1)))
					capture(i, j, board);
			}
		}

		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				if (board[i][j] == 'O') board[i][j] = 'X';
			}
		}

		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				if (board[i][j] == 'P') board[i][j] = 'O';
			}
		}
	}
};

int main() {
	Solution s;

	board_t b1 = {
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X'},
	};

	board_t b2 = {
		{'O', 'O', 'O', 'O', 'X', 'X'}, {'O', 'O', 'O', 'O', 'O', 'O'},
		{'O', 'X', 'O', 'X', 'O', 'O'}, {'O', 'X', 'O', 'O', 'X', 'O'},
		{'O', 'X', 'O', 'X', 'O', 'O'}, {'O', 'X', 'O', 'O', 'O', 'O'},
	};

	s.solve(b1);
	s.solve(b2);

	return 0;
}