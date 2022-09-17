#include <bits/stdc++.h>

using std::string;
using std::vector;

class Solution {
   public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res = {""};
        if (s.length() == 0) return res;

        for (auto ch : s) {
            vector<string> perms = {};
            if (isalpha(ch)) {
                for (auto o : res) {
                    perms.push_back(o + (char)std::tolower(ch));
                    perms.push_back(o + (char)std::toupper(ch));
                }
            } else {
                for (auto o : res) {
                    perms.push_back(o + ch);
                }
            }
            res = perms;
        }

        return res;
    }
};

int main() {
    Solution s;

    auto res = s.letterCasePermutation("a1b2");

    return 0;
}