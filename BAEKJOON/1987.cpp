#include <iostream>
#include <cmath>

using namespace std;

int r, c;
char board[21][21];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int visited[26];
int ans;

void printBoard() {
    for(int i = 0 ; i < r ; i++) {
        for(int j = 0 ; j < c ; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void dfs(int cy, int cx, int cnt) {
    ans = max(ans, cnt);

    for(int i = 0 ; i < 4 ; i++) {
        int ny = cy + dy[i];
        int nx = cx + dx[i];

        if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        if(visited[board[ny][nx] - 'A']) continue;

        visited[board[ny][nx] - 'A'] = 1;
        dfs(ny, nx, cnt + 1);
        visited[board[ny][nx] - 'A'] = 0;
    }
}

int main() {
    cin >> r >> c;
    for(int i = 0 ; i < r ; i++) {
        for(int j = 0 ; j < c ; j++) {
            cin >> board[i][j];
        }
    }

    visited[board[0][0] - 'A'] = 1;
    dfs(0, 0, 1);

    cout << ans << '\n';
    return 0;
}