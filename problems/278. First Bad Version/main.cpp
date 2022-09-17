#include <bits/stdc++.h>

// The API isBadVersion is defined for you.
bool isBadVersion(int version) {
    if (version < 4) return false;
    return true;
}

class Solution {
   public:
    int firstBadVersion(int n) {
        long l = 1, r = n;
        int bad = 0;
        while (l <= r) {
            long long mid = (l + r) / 2;
            bool res = isBadVersion(mid);

            if (res) {
                bad = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return bad;
    }
};

int main() {
    Solution s;
    std::cout << s.firstBadVersion(5) << std::endl;
    return 0;
}