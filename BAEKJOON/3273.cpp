#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x;
vector<int> arr;

int main() {
	cin >> n;
	for (int i = 0, num; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}
	cin >> x;
	
	sort(arr.begin(), arr.end());

	int cnt = 0;
	int left = 0, right = n - 1;

	while (left < right) {
		int sum = arr[left] + arr[right];

		if (sum == x) {
			cnt++;
			right--;
		}
		else if(sum < x) {
			left++;
		}
		else {
			right--;
		}
	}
	
	cout << cnt << '\n';
	return 0;
}