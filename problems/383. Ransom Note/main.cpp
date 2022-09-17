#include <bits/stdc++.h>

using std::string;

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> m;
        bool res = true;

        for (auto ch : magazine) {
            m[ch]++;
        }

        for (auto ch : ransomNote) {
            m[ch]--;
        }

        for (auto ch : ransomNote) {
            res &= (m[ch] >= 0);
        }

        return res;
    }
};

int main() {
    Solution s;

    std::cout << std::boolalpha << s.canConstruct("a", "b") << std::endl;
    std::cout << std::boolalpha << s.canConstruct("aa", "ab") << std::endl;
    std::cout << std::boolalpha << s.canConstruct("aa", "aab") << std::endl;

    return 0;
}