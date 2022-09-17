#include <bits/stdc++.h>

class Solution {
   public:
    bool isPowerOfTwo(int n) {
        return (n && !(n & (n - 1)));
    }
};

int main() {
    Solution s;

    std::cout << std::boolalpha << s.isPowerOfTwo(0) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfTwo(1) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfTwo(2) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfTwo(3) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfTwo(15) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfTwo(8) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfTwo(16) << std::endl;

    return 0;
}