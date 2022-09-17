#include <bits/stdc++.h>

using std::string;

class Solution {
   public:
    bool backspaceCompare(string s, string t) {
        std::stack<char> ss, ts;

        for (auto ch : s) {
            if (ch != '#')
                ss.push(ch);
            else if (!ss.empty())
                ss.pop();
        }

        for (auto ch : t) {
            if (ch != '#')
                ts.push(ch);
            else if (!ts.empty())
                ts.pop();
        }

        return ss == ts;
    }
};

int main() {
    Solution s;

    std::cout << std::boolalpha << s.backspaceCompare("ab#c", "ad#c") << std::endl;
    std::cout << std::boolalpha << s.backspaceCompare("ab##", "c#d#") << std::endl;
    std::cout << std::boolalpha << s.backspaceCompare("a#c", "b") << std::endl;
    std::cout << std::boolalpha << s.backspaceCompare("y#fo##f", "y#f#o##f") << std::endl;

    return 0;
}