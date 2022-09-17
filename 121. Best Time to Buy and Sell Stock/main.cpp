#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int res = 0;
        for (int r = 1; r < prices.size(); ++r) {
            if (prices[l] < prices[r]) {
                res = std::max(res, (prices[r] - prices[l]));
            } else
                l++;
        }

        return res;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {7, 1, 5, 3, 6, 4};

    std::cout << s.maxProfit(v1) << std::endl;

    return 0;
}