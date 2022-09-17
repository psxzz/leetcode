#include <bits/stdc++.h>

using std::string;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> m;
        bool res = true;

        for (auto ch : s) {
            m[ch]--;
        }
        for (auto ch : t) {
            m[ch]++;
        }
        for (auto& it : m) {
            res &= (it.second == 0);
        }

        return res;
    }
};

int main() {
    Solution s;

    std::cout << std::boolalpha << s.isAnagram("anagram", "nagaram") << std::endl;
    std::cout << std::boolalpha << s.isAnagram("rat", "car") << std::endl;
    std::cout << std::boolalpha << s.isAnagram("a", "ab") << std::endl;

    return 0;
}