#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;

int main() {
	cin >> n >> m;
	for (int i = 0, num; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	int cnt = 0;
	int left = 0, right = 0;
	int sum = arr[0];

	while (right < n) {
		if (sum < m) {
			sum += arr[++right];
		}
		else if (sum == m) {
			cnt++;
			sum += arr[++right];
		}
		else {
			sum -= arr[left++];
		}
	}

	cout << cnt << '\n';
	return 0;
}