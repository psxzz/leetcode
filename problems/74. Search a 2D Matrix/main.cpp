#include <bits/stdc++.h>

using std::vector;
using matrix_t = vector<vector<int>>;

class Solution {
  public:
    bool searchMatrix(matrix_t& matrix, int target) {
        int row = 0;
        while (row != matrix.size()) {
            int row_size = matrix[row].size();

            if (matrix[row][row_size - 1] == target) return true;

            if (matrix[row][row_size - 1] > target)
                return std::binary_search(matrix[row].begin(),
                                          matrix[row].end(), target);

            row++;
        }

        return false;
    }
};

int main() {
    Solution s;

    matrix_t m1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60},
    };

    std::cout << std::boolalpha << s.searchMatrix(m1, 3) << std::endl;
    std::cout << std::boolalpha << s.searchMatrix(m1, 13) << std::endl;

    return 0;
}