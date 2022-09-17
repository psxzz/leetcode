#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            std::sort(stones.begin(), stones.end());
            int y = stones.back();
            stones.pop_back();
            int x = stones.back();
            stones.pop_back();

            if (x == y) continue;

            if (x != y) stones.push_back(y - x);
        }

        return stones.empty() ? 0 : stones.front();
    }
};

int main() {
    Solution s;

    vector<int> v1 = {2, 7, 4, 1, 8, 1};
    vector<int> v2 = {1};

    std::cout << s.lastStoneWeight(v1) << std::endl;
    std::cout << s.lastStoneWeight(v2) << std::endl;

    return 0;
}