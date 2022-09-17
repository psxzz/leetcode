#include <bits/stdc++.h>

using std::vector;
using image_t = vector<vector<int>>;

class Solution {
   public:
    image_t floodFill(image_t& image, int sr, int sc, int color) {
        int currColor = image[sr][sc];
        image[sr][sc] = color;
        int up = sr - 1, down = sr + 1, left = sc - 1, right = sc + 1;

        if (up >= 0 && image[up][sc] == currColor && image[up][sc] != color)
            image = floodFill(image, up, sc, color);

        if (down < image.size() &&
            image[down][sc] == currColor && image[down][sc] != color)
            image = floodFill(image, down, sc, color);

        if (left >= 0 &&
            image[sr][left] == currColor && image[sr][left] != color)
            image = floodFill(image, sr, left, color);

        if (right < image[sr].size() &&
            image[sr][right] == currColor && image[sr][right] != color)
            image = floodFill(image, sr, right, color);

        return image;
    }
};

int main() {
    Solution s;

    image_t img1 = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    s.floodFill(img1, 1, 1, 2);

    std::cout << std::endl;

    return 0;
}