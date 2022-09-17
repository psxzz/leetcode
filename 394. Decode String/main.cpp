#include <bits/stdc++.h>

using std::string;

class Solution {
   public:
    string decodeString(string s) {
        std::stack<char> ss;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != ']')
                ss.push(s[i]);
            else {
                string substr = "";
                while (ss.top() != '[') {
                    substr = ss.top() + substr;
                    ss.pop();
                }
                ss.pop();

                string k = "";
                while (!ss.empty() && isdigit(ss.top())) {
                    k = ss.top() + k;
                    ss.pop();
                }

                for (int i = 0; i < std::atoi(k.data()); ++i) {
                    for (auto ch : substr) {
                        ss.push(ch);
                    }
                }
            }
        }
        string res;

        while (!ss.empty()) {
            res = ss.top() + res;
            ss.pop();
        }

        return res;
    }
};

int main() {
    Solution s;

    std::cout << s.decodeString("3[a]2[bc]") << std::endl;
    std::cout << s.decodeString("3[a2[c]]") << std::endl;
    std::cout << s.decodeString("2[abc]3[cd]ef") << std::endl;

    return 0;
}