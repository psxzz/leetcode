#include <bits/stdc++.h>

using std::string;

class Solution {
   public:
    bool isValid(string s) {
        std::stack<char> brackets;
        for (auto ch : s) {
            if (ch == '[' || ch == '{' || ch == '(') {
                brackets.push(ch);
            } else {
                switch (ch) {
                    case ']':
                        if (!brackets.empty() && brackets.top() == '[')
                            brackets.pop();
                        else
                            return false;
                        break;
                    case '}':
                        if (!brackets.empty() && brackets.top() == '{')
                            brackets.pop();
                        else
                            return false;
                        break;
                    case ')':
                        if (!brackets.empty() && brackets.top() == '(')
                            brackets.pop();
                        else
                            return false;
                        break;

                    default:
                        break;
                }
            }
        }

        return brackets.empty();
    }
};

int main() {
    Solution s;
    string s1 = "()";
    string s2 = "(){}[]";
    string s3 = "([{}][()])";
    string s4 = "]";

    std::cout << std::boolalpha << s.isValid(s1) << std::endl;
    std::cout << std::boolalpha << s.isValid(s2) << std::endl;
    std::cout << std::boolalpha << s.isValid(s3) << std::endl;
    std::cout << std::boolalpha << s.isValid(s4) << std::endl;

    return 0;
}