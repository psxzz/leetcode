#include <bits/stdc++.h>

using std::string;

class Solution {
   public:
    string reverseWords(string s) {
        int l = 0, r = 0;
        int space = 0;
        while (space++ < s.length()) {
            if (s[space] != ' ') continue;

            r = space - 1;
            while (l < r) {
                char tmp = s[l];
                s[l] = s[r];
                s[r] = tmp;
                l++;
                r--;
            }

            l = space + 1;
        }

        r = s.length() - 1;
        while (l < r) {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }

        return s;
    }
};

int main() {
    Solution s;

    string s1 = "Let's take LeetCode contest";
    string s2 = "God Ding";

    std::cout << s.reverseWords(s1) << std::endl;
    std::cout << s.reverseWords(s2) << std::endl;

    return 0;
}