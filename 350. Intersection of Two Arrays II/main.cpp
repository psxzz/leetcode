#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    // Two pointers approach
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersection;
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        int l1 = 0, l2 = 0;

        while (l1 < nums1.size() && l2 < nums2.size()) {
            if (nums1[l1] < nums2[l2])
                l1++;
            else if (nums1[l1] > nums2[l2])
                l2++;
            else {
                intersection.push_back(nums1[l1]);
                l1++;
                l2++;
            }
        }

        return intersection;
    }

    // hash table approach
    vector<int> intersect_hash(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> m;
        vector<int> intersection;

        for (auto& num : nums1) {
            m[num]++;
        }

        for (auto& num : nums2) {
            if (m.find(num) != m.end()) {
                intersection.push_back(num);
                m[num]--;
                if (m[num] == 0) m.erase(num);
            }
        }

        return intersection;
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

    vector<int> v1 = {1, 2, 2, 1}, v2 = {2, 2};
    vector<int> res = s.intersect_hash(v1, v2);

    s.printVector(res);

    v1 = {4, 9, 5}, v2 = {9, 4, 9, 8, 4};
    res = s.intersect_hash(v1, v2);

    s.printVector(res);

    return 0;
}