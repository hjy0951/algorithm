#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define MAXN 1000

int r, c;
int map[MAXN][MAXN];
int visit[MAXN][MAXN];
int fire[MAXN][MAXN];
queue<pair<int,int>> sq;
queue<pair<int,int>> fireq;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int minTime = 987987987;

void escape() {
    while(!sq.empty()) {
        int cy = sq.front().first;
        int cx = sq.front().second;
        sq.pop();

        for(int i = 0 ; i < 4 ; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            int time = visit[cy][cx] + 1;

            // 벽 바깥으로 탈출
            if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
                if(minTime > time) minTime = time;
                continue;
            }
            if(map[ny][nx] != 0 || visit[ny][nx]) continue;
            if(fire[ny][nx] > 0 && fire[ny][nx] <= time) continue;

            sq.push(make_pair(ny, nx));
            visit[ny][nx] = visit[cy][cx] + 1;
        }
    }
}

void spreadFire() {
    while(!fireq.empty()) {
        int cy = fireq.front().first;
        int cx = fireq.front().second;
        fireq.pop();

        for(int i = 0 ; i < 4 ; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            int time = visit[cy][cx] + 1;

            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if(map[ny][nx] != 0 || fire[ny][nx]) continue;

            fireq.push(make_pair(ny, nx));
            fire[ny][nx] = fire[cy][cx] + 1;
        }
    }
}

int main() {
    cin >> r >> c;
    for(int i = 0 ; i < r ; i++) {
        string str;
        cin >> str;

        for(int j = 0 ; j < c ; j++) {
            char current = str[j];
            if(current == 'J') {
                sq.push(make_pair(i, j));
                visit[i][j] = 1;
            }
            else if(current == '#') {
                map[i][j] = 1;
            }
            else if(current == 'F') {
                fireq.push(make_pair(i, j));
                fire[i][j] = 1;
            }
        }
    }

    spreadFire();
    escape();

    if(minTime == 987987987) cout << "IMPOSSIBLE\n";
    else cout << minTime - 1 << '\n';

    return 0;
}