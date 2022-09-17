#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;

        for (l = 0; l < s.size() / 2; ++l) {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            r--;
        }
    }

    void print_vector(vector<char>& v) {
        for (auto x : v) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution s;

    vector<char> v1 = {'H', 'a', 'n', 'n', 'a', 'h'};
    vector<char> v2 = {'H', 'e', 'l', 'l', 'o'};
    vector<char> v3 = {'A', ' ', 'm', 'a', 'n', ',', ' ', 'a', ' ', 'p', 'l', 'a', 'n', ',', ' ', 'a', ' ', 'c', 'a', 'n', 'a', 'l', ':', ' ', 'P', 'a', 'n', 'a', 'm', 'a'};

    s.reverseString(v1);
    s.print_vector(v1);
    s.reverseString(v2);
    s.print_vector(v2);

    s.reverseString(v3);
    s.print_vector(v3);

    return 0;
}