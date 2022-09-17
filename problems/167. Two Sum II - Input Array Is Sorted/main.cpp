#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;

        while (l != r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) return vector<int>({l + 1, r + 1});

            if (sum < target)
                l++;
            else
                r--;
        }
        return vector<int>();
    }

    void print_vector(vector<int>& v) {
        for (auto x : v) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {2, 7, 11, 15};
    vector<int> v2 = {2, 3, 4};
    vector<int> v3 = {-1, 0};

    vector<int> res1 = s.twoSum(v1, 9);
    vector<int> res2 = s.twoSum(v2, 6);
    vector<int> res3 = s.twoSum(v3, -1);

    s.print_vector(res1);
    s.print_vector(res2);
    s.print_vector(res3);

    return 0;
}