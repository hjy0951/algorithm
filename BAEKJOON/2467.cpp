#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<int> solutions;

int main() {
	cin >> n;
	for (int i = 0, num; i < n; i++) {
		cin >> num;
		solutions.push_back(num);
	}

	int left = 0, right = n - 1;
	int minSum = 2000000000;
	int minLeft, minRight;

	while (left < right) {
		int sum = solutions[left] + solutions[right];

		if (minSum > abs(sum)) {
			minLeft = left;
			minRight = right;
			minSum = abs(sum);
		}

		if (sum > 0) {
			right--;
		}
		else {
			left++;
		}
	}

	cout << solutions[minLeft] << ' ' << solutions[minRight] << '\n';

	return 0;
}