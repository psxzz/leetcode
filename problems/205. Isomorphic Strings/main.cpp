#include <iostream>
#include <string>
#include <unordered_map>

using std::string;

class Solution {
   public:
    std::unordered_map<char, char> m;
    bool isIsomorphic(string s, string t) {
        for (size_t i = 0; i < s.length(); ++i) {
            char ch = s[i];
            char ch2 = t[i];
            if (m.find(ch) == m.end()) {
                for (auto it = m.begin(); it != m.end(); ++it) {
                    if (it->second == ch2) return false;
                }
                m[ch] = t[i];
            } else {
                if (m[ch] != t[i]) return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;

    string s1 = "baba";
    string s2 = "baba";

    std::cout << std::boolalpha << s.isIsomorphic(s1, s2) << std::endl;

    return 0;
}