#include <bits/stdc++.h>

using std::string;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> cs;
        int len = 0;
        int l = 0;

        for (int r = 0; r < s.length(); ++r) {
            while (cs.count(s[r]) != 0) {
                cs.erase(s[l]);
                l++;
            }
            cs.insert(s[r]);
            len = std::max(len, r - l + 1);
        }

        return len;
    }
};

int main() {
    Solution s;

    string s1 = {"abcabcbb"};
    string s2 = {"bbbbb"};
    string s3 = {"pwwkew"};

    std::cout << s.lengthOfLongestSubstring(s1) << std::endl;
    std::cout << s.lengthOfLongestSubstring(s2) << std::endl;
    std::cout << s.lengthOfLongestSubstring(s3) << std::endl;

    return 0;
}