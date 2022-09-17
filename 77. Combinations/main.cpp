#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>                   res;
        std::function<void(int, vector<int>)> backtrack =
            [&res, &n, &k, &backtrack](int start, vector<int> comb) {
                if (comb.size() == k) {
                    res.push_back(comb);
                    return;
                }

                for (int i = start; i < n + 1; ++i) {
                    comb.push_back(i);
                    backtrack(i + 1, comb);
                    comb.pop_back();
                }
                return;
            };

        backtrack(1, vector<int>());
        return res;
    }
};

int main() {
    Solution s;

    vector<vector<int>> res1 = s.combine(4, 2);

    return 0;
}