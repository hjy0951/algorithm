#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAXN 200001

int check[MAXN];
int n, k;
vector<int> arr;

int main() {
	cin >> n >> k;
	for (int i = 0, num; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	int left = 0, right = 0;
	int maxCnt = 1;

	while (left <= right && right < n) {
		int current = arr[right];

		if (check[current] < k) {
			check[current]++;
			right++;
			maxCnt = max(maxCnt, right - left);
		}
		else if (check[current] == k) {
			check[arr[left]]--;
			left++;
		}
	}

	cout << maxCnt << '\n';

	return 0;
}