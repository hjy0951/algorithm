#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> times;

int main() {
	cin >> n;

	for (int i = 0, num; i < n; i++) {
		cin >> num;
		times.push_back(num);
	}

	sort(times.begin(), times.end());

	int total = 0;
	int prevSum = 0;
	for (int i = 0; i < n; i++) {
		int current = times[i];

		total += prevSum + current;
		prevSum += current;
	}

	cout << total << '\n';
	return 0;
}
