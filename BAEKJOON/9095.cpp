#include <iostream>

using namespace std;

int n;
int dp[11];

void solution() {
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for(int i = 1; i < 10; i++) {
        for(int j = 1 ; j <= 3 ; j++) {
            int next = i + j;
            if(next > 10) continue;

            dp[next] += dp[i];
        }
    }
}

int main() {
    int tc;
    cin >> tc;

    solution();

    for(int i = 0 ; i < tc ; i++) {
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}