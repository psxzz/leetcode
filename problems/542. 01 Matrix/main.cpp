#include <bits/stdc++.h>

using std::vector;
using matrix_t = vector<vector<int>>;

class Solution {
   public:
    matrix_t updateMatrix(matrix_t& mat) {
        for (int row = 0; row < mat.size(); ++row) {
            for (int col = 0; col < mat[row].size(); ++col) {
                if (mat[row][col] != 0) {
                    int left = (col - 1 >= 0) ? mat[row][col - 1] : 100;
                    int up = (row - 1 >= 0) ? mat[row - 1][col] : 100;
                    mat[row][col] = std::min(left, up) + 1;
                } else {
                    mat[row][col] = 0;
                }
            }
        }

        for (int row = mat.size() - 1; row >= 0; --row) {
            for (int col = mat[row].size() - 1; col >= 0; --col) {
                if (mat[row][col] != 0) {
                    int right = (col + 1 < mat[row].size()) ? mat[row][col + 1] : 100;
                    int down = (row + 1 < mat.size()) ? mat[row + 1][col] : 100;
                    mat[row][col] = std::min(mat[row][col], std::min(right, down) + 1);
                } else {
                    mat[row][col] = 0;
                }
            }
        }

        return mat;
    }
};

int main() {
    Solution s;

    matrix_t m1 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };

    matrix_t m2 = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1},
    };

    matrix_t res1 = s.updateMatrix(m1);
    matrix_t res2 = s.updateMatrix(m2);

    std::cout << "END" << std::endl;

    return 0;
}