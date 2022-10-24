#include <bits/stdc++.h>

const int mod = 1e9 + 7;

class Solution {
  public:
	int concatenatedBinary(int n) {
		long long int val = 0;
		for (int i = 1; i <= n; ++i) {
			val = ((val << (1 + int(log2(i)))) % mod + i) % mod;
		}

		return val;
	}
};

int main() {
	Solution s;

	std::cout << s.concatenatedBinary(12) << std::endl;

	return 0;
}