#include <bits/stdc++.h>

class Solution {
   public:
    int fib(int n) {
        if (n == 0) return 0;
        int prev = 0;
        int curr = 1;
        for (int i = 0; i < n - 1; ++i) {
            int tmp = curr;
            curr += prev;
            prev = tmp;
        }

        return curr;
    }
};

int main() {
    Solution s;

    std::cout << s.fib(30) << std::endl;

    return 0;
}