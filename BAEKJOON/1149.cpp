#include <iostream>
#include <cmath>

using namespace std;

int n;
int cost[1000][3];
int dp[1000][3];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		dp[0][i] = cost[0][i];
	}
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}

	int answer = 987987987;
	for (int i = 0; i < 3; i++) {
		answer = min(answer, dp[n - 1][i]);
	}

	cout << answer << '\n';
	return 0;
}