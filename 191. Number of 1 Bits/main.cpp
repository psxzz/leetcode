#include <bits/stdc++.h>

class Solution {
   public:
    int hammingWeight(uint32_t n) {
        // return __builtin_popcount(n);

        size_t count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }

        return count;
    }
};

int main() {
    Solution s;

    std::cout << s.hammingWeight(6) << std::endl;
    std::cout << s.hammingWeight(11) << std::endl;
    std::cout << s.hammingWeight(16) << std::endl;
    std::cout << s.hammingWeight(15) << std::endl;

    return 0;
}