#include <bits/stdc++.h>

using std::string;
using std::vector;

class Solution {
   public:
    int longestPalindrome(string s) {
        vector<int> count(128, 0);
        int odds = 0;
        // Counting chars
        for (auto ch : s) {
            count[ch]++;
        }

        // Counting odds
        for (auto ch : count) {
            odds += (ch & 1);
        }

        return s.size() - odds + (odds > 0);
    }
};

int main() {
    Solution s;

    string s1 = "abccccdd";
    string s2 = "a";
    string s3 = "ccc";

    std::cout << s.longestPalindrome(s1) << std::endl;
    std::cout << s.longestPalindrome(s2) << std::endl;
    std::cout << s.longestPalindrome(s3) << std::endl;

    return 0;
}