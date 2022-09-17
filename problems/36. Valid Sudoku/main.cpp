#include <bits/stdc++.h>

using std::vector;
using board_t = vector<vector<char>>;

#define BOARD_SIZE 9

class Solution {
    bool validateRow(vector<char>& row) {
        std::set<int> s;
        for (auto ch : row) {
            if (ch == '.') continue;

            auto ret = s.insert(ch - '0');
            if (!ret.second) return false;
        }
        return true;
    }

    bool validateCol(board_t& b, int col) {
        std::set<int> s;
        for (auto& row : b) {
            if (row[col] == '.') continue;

            auto ret = s.insert(row[col] - '0');
            if (!ret.second) return false;
        }

        return true;
    }

    bool validateBox(board_t& b, int row, int col) {
        std::set<int> s;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (b[row + i][col + j] == '.') continue;

                auto ret = s.insert(b[row + i][col + j] - '0');
                if (!ret.second) return false;
            }
        }
        return true;
    }

   public:
    bool isValidSudoku(board_t& board) {
        bool res = true;
        for (int i = 0; i < BOARD_SIZE && res; ++i) {
            res &= validateRow(board[i]);
            res &= validateCol(board, i);

            if (i % 3 == 0) {
                res &= validateBox(board, 0, i);
                res &= validateBox(board, 3, i);
                res &= validateBox(board, 6, i);
            }
        }

        return res;
    }
};

int main() {
    Solution s;

    board_t b1 = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

    board_t b2 = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

    // [
    //     [ ".", ".", ".", ".", "5", ".", ".", "1", "." ],
    //     [ ".", "4", ".", "3", ".", ".", ".", ".", "." ],
    //     [ ".", ".", ".", ".", ".", "3", ".", ".", "1" ],
    //     [ "8", ".", ".", ".", ".", ".", ".", "2", "." ],
    //     [ ".", ".", "2", ".", "7", ".", ".", ".", "." ],
    //     [ ".", "1", "5", ".", ".", ".", ".", ".", "." ],
    //     [ ".", ".", ".", ".", ".", "2", ".", ".", "." ],
    //     [ ".", "2", ".", "9", ".", ".", ".", ".", "." ],
    //     [ ".", ".", "4", ".", ".", ".", ".", ".", "." ]
    // ]

    std::cout
        << std::boolalpha << s.isValidSudoku(b1) << std::endl;
    std::cout << std::boolalpha << s.isValidSudoku(b2) << std::endl;

    return 0;
}