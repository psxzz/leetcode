#include <bits/stdc++.h>

class Solution {
   public:
    bool isPowerOfFour(int n) {
        return n != 0 && ((n & (n - 1)) == 0) && !(n & 0xAAAAAAAA);
    }
};

int main() {
    Solution s;

    std::cout << std::boolalpha << s.isPowerOfFour(4) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfFour(5) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfFour(8) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfFour(16) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfFour(32) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfFour(64) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfFour(256) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfFour(512) << std::endl;

    return 0;
}