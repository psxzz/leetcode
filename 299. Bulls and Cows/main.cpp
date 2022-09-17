#include <bits/stdc++.h>

using std::string;
using std::vector;

class Solution {
   public:
    string getHint(string secret, string guess) {
        int cows = 0, bulls = 0;
        vector<int> s_nums(10, 0);
        vector<int> g_nums(10, 0);

        for (int i = 0; i < secret.length(); ++i) {
            char s_ch = secret[i], g_ch = guess[i];
            if (s_ch == g_ch) {
                bulls++;
            } else {
                s_nums[s_ch - '0']++;
                g_nums[g_ch - '0']++;
            }
        }

        for (int i = 0; i < s_nums.size(); ++i)
            cows += std::min(s_nums[i], g_nums[i]);

        string res = std::to_string(bulls) + "A" + std::to_string(cows) + "B";
        return res;
    }
};

int main() {
    Solution s;

    std::cout << s.getHint("1807", "7810") << std::endl;
    std::cout << s.getHint("1123", "0111") << std::endl;
    std::cout << s.getHint("1122", "3456") << std::endl;

    return 0;
}