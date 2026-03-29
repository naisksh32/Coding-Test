#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, K, X;

struct Edge {
	int to;
	int cost;

	bool operator<(Edge right) const {
		if (cost > right.cost) return true;
		if (cost < right.cost) return false;
		return false;
	}
};
vector<Edge> alis[300001];
int dist[300001];

void dijkstra(int start) {
	for (int i = 0; i < 300001; i++) {
		dist[i] = 21e8;
	}

	priority_queue<Edge> pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty()) {
		Edge now = pq.top(); pq.pop();

		if (dist[now.to] < now.cost) continue;

		for (int i = 0; i < alis[now.to].size(); i++) {
			Edge next = alis[now.to][i];
			int next_cost = dist[now.to] + next.cost;

			if (dist[next.to] <= next_cost) continue;

			dist[next.to] = next_cost;
			pq.push({ next.to, next_cost });
		}
	}
}

int main() {
	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; i++) {
		int from, to;
		int cost = 1;
		cin >> from >> to;

		alis[from].push_back({ to, cost });
	}

	dijkstra(X);

	vector<int> city;
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
			city.push_back(i);
		}
	}

	if (!city.empty()) {
		for (int i = 0; i < city.size(); i++) {
			cout << city[i] << '\n';
		}
	}
	else {
		cout << -1;
	}


	return 0;
}