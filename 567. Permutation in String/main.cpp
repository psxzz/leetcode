#include <bits/stdc++.h>

using std::string;
using std::vector;

class Solution {
   public:
    vector<int> countFrequency(string s, int l, int r) {
        vector<int> f(26, 0);
        while (l < r) {
            f[s[l] - 'a']++;
            l++;
        }
        return f;
    }

    bool checkInclusion(string s1, string s2) {
        vector<int> s1Freq = countFrequency(s1, 0, s1.length());
        vector<int> wFreq(26, 0);
        int l = 0, r = 0 + s1.length();

        while (r <= s2.length()) {
            wFreq = countFrequency(s2, l, r);

            if (s1Freq == wFreq) return true;
            l++;
            r++;
        }

        return false;
    }
};

int main() {
    Solution s;

    string s1 = "ab";
    string s2 = "eidbaooo";
    std::cout << std::boolalpha << s.checkInclusion(s1, s2) << std::endl;

    s2 = "eidboaoo";
    std::cout << std::boolalpha << s.checkInclusion(s1, s2) << std::endl;

    return 0;
}