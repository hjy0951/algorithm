#include <iostream>
#include <cmath>

using namespace std;

int n;
int dp[1000001];
int visit[1000001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = i;
	}

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
    }
    cout << dp[n] - 1 << endl;

    int count = n;

    cout << n << " ";

    while (count > 1) {
        if (count % 3 == 0 && dp[count / 3] == dp[count] - 1) {
            cout << count / 3 << " ";
            count /= 3;
        }
        else if (count % 2 == 0 && dp[count / 2] == dp[count] - 1) {
            cout << count / 2 << " ";
            count /= 2;
        }
        else {
            cout << count - 1 << " ";
            count -= 1;
        }
    }
	return 0;
}