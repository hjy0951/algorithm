#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> ropes;

int main() {
	cin >> n;
	for (int i = 0, num; i < n; i++) {
		cin >> num;
		ropes.push_back(num);
	}

	sort(ropes.begin(), ropes.end());

	int maxWeight = ropes[ropes.size() - 1];
	int cnt = 1;

	for (int i = ropes.size() - 2; i >= 0; i--) {
		int current = ropes[i];
		int currentWeight = (cnt + 1) * current;

		if (maxWeight < currentWeight) maxWeight = currentWeight;
		cnt++;
	}

	cout << maxWeight << '\n';
	return 0;
}