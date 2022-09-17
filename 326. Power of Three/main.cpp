#include <bits/stdc++.h>

class Solution {
   public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;

        while (n > 1) {
            if (n % 3 != 0) return false;
            n /= 3;
        }

        return true;
    }
};

int main() {
    Solution s;

    std::cout << std::boolalpha << s.isPowerOfThree(0) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfThree(1) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfThree(2) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfThree(3) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfThree(4) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfThree(6) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfThree(9) << std::endl;
    std::cout << std::boolalpha << s.isPowerOfThree(27) << std::endl;

    return 0;
}