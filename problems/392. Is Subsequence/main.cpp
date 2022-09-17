#include <iostream>
#include <string>

using std::string;

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        if (!s.length()) return true;
        if (!t.length()) return false;

        auto s_it = s.begin();

        for (auto t_it = t.begin(); t_it != t.end(); ++t_it) {
            if (*t_it == *s_it) ++s_it;
        }

        if (s_it == s.end()) return true;

        return false;
    }
};

int main() {
    Solution s;

    string s1 = "abc";
    string s2 = "ahbgdc";

    std::cout << std::boolalpha << s.isSubsequence(s1, s2) << std::endl;

    return 0;
}