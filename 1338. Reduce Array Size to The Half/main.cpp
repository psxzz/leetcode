#include <bits/stdc++.h>

using std::vector;

class Solution {
   public:
    int minSetSize(vector<int>& arr) {
        int arr_size = arr.size();
        int curr_size = arr.size();
        int to_remove = 0;
        std::map<int, int> m;
        std::priority_queue<int> pq;

        for (auto& num : arr) {
            m[num]++;
        }

        for (auto it = m.begin(); it != m.end(); ++it) {
            pq.push(it->second);
        }

        while (curr_size > arr_size / 2) {
            curr_size -= pq.top();
            to_remove++;
            pq.pop();
        }

        return to_remove;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
    vector<int> v2 = {7, 7, 7, 7, 7, 7};

    std::cout << s.minSetSize(v1) << std::endl;
    std::cout << s.minSetSize(v2) << std::endl;

    return 0;
}