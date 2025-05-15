#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> coins;

int main() {
	cin >> n >> k;
	for (int i = 0, num; i < n; i++) {
		cin >> num;
		coins.push_back(num);
	}

	int cnt = 0;
	int rest = k;
	int idx = n - 1;
	while (rest > 0 && idx >= 0) {
		int current = coins[idx];
		if (current > rest) {
			idx--;
			continue;
		}

		cnt += rest / current;
		rest -= (rest / current) * current;
	}

	cout << cnt << '\n';
	return 0;
}