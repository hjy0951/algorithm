#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAXN 301

int n;
vector<int> stairs;
int dp[MAXN];

void solution() {
    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    dp[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);

    for(int i = 4 ; i <= n ; i++) {
        dp[i] = max(dp[i-2] + stairs[i], dp[i-3] + stairs[i-1] + stairs[i]);
    }
}

int main() {
    cin >> n;
    stairs.push_back(0);
    for(int i = 0, num ; i < n ; i++) {
        cin >> num;
        stairs.push_back(num);
    }

    solution();

    cout << dp[n] << '\n';
    return 0;
}