#include <bits/stdc++.h>

using std::vector;

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int l = 0, r = height.size() - 1;
        int maxArea = 0;
        while (r - l > 0) {
            int area = (r - l) * std::min(height[l], height[r]);
            maxArea = std::max(maxArea, area);
            if (height[l] < height[r])
                l++;
            else
                r--;
        }

        return maxArea;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> v2 = {1, 1};

    std::cout << s.maxArea(v1) << std::endl;
    std::cout << s.maxArea(v2) << std::endl;

    return 0;
}