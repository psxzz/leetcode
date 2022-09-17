#include <bits/stdc++.h>

using std::vector;

using matrix_t = vector<vector<int>>;

class Solution {
   public:
    matrix_t matrixReshape(matrix_t& mat, int r, int c) {
        int mat_rows = mat.size(), mat_cols = mat[0].size();
        if ((r * c) != (mat_rows * mat_cols)) return mat;

        matrix_t res(r, vector<int>(c, 0));
        int row_num = 0, col_num = 0;

        for (int i = 0; i < mat_rows; ++i) {
            for (int j = 0; j < mat_cols; ++j) {
                res[row_num][col_num] = mat[i][j];
                col_num++;
                if (col_num == c) {
                    col_num = 0;
                    row_num++;
                }
            }
        }

        return res;
    }

    void printMatrix(matrix_t m) {
        for (auto& row : m) {
            for (auto& col : row) {
                std::cout << col << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Solution s;

    matrix_t m1 = {
        {1, 2},
        {3, 4},
    };
    s.printMatrix(m1);

    matrix_t res = s.matrixReshape(m1, 1, 4);
    s.printMatrix(res);

    return 0;
}