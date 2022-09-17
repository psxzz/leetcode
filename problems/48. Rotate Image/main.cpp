#include <bits/stdc++.h>

using std::vector;
using img_t = vector<vector<int>>;

class Solution {
   public:
    void rotate(img_t& matrix) {
        int l = 0, r = matrix.size() - 1;
        while (l < r) {
            for (int i = 0; i < r - l; ++i) {
                int top = l, bottom = r;
                int topLeft = matrix[top][l + i];
                matrix[top][l + i] = matrix[bottom - i][l];
                matrix[bottom - i][l] = matrix[bottom][r - i];
                matrix[bottom][r - i] = matrix[top + i][r];
                matrix[top + i][r] = topLeft;
            }

            l++;
            r--;
        }
    }
};

int main() {
    Solution s;

    img_t img1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    img_t img2 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16},
    };

    s.rotate(img1);
    s.rotate(img2);

    return 0;
}