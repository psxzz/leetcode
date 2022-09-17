#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while (i >= 0) nums1[k--] = nums1[i--];
        while (j >= 0) nums1[k--] = nums2[j--];
    }

    void printVector(vector<int>& v) {
        for (auto& x : v) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {4, 5, 6, 0, 0, 0};
    vector<int> v2 = {1, 2, 3};

    s.merge(v1, 3, v2, 3);

    s.printVector(v1);

    return 0;
}