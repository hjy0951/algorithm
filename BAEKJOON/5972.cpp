#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>

using namespace std;

#define MAXN 50001

int n, m;
vector<pair<int, int>> graph[MAXN];


int dijkstra(int start) {
    vector<int> dist(n + 1, 987987987);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push(make_pair(0, start)); // (거리, 노드)

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        int cost = top.first;
        int cur = top.second;

        if (dist[cur] < cost) continue;

        for (int i = 0; i < graph[cur].size(); ++i) {
            int next = graph[cur][i].first;
            int weight = graph[cur][i].second;

            int nextDist = cost + weight;

            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push(make_pair(nextDist, next));
            }
        }
    }

    return dist[n];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}

    cout << dijkstra(1) << '\n';

	return 0;
}