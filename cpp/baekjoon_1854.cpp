#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int N, M, K;
struct Edge {
	int to;
	int cost;

	bool operator<(Edge right)const {
		if (cost > right.cost) return true;
		if (cost < right.cost) return false;
		return false;
	}
};
vector<Edge> alis[1001];

priority_queue<int> dist[1001];

void dijkstra(int st) {
	// 거리 배열 초기화
	for (int i = 1; i <= N; i++) {
		while (!dist[i].empty()) {
			dist[i].pop();
		}
	}

	// 다익스트라 초기 우선순위 큐 설정
	priority_queue<Edge> pq;
	pq.push({ st, 0 });
	dist[st].push(0);

	// 다익스트라 큐가 빌 때까지 진행
	while (!pq.empty()) {
		Edge now = pq.top(); pq.pop();

		// 갈 수 있는 다음 경로
		for (int i = 0; i < alis[now.to].size(); i++) {
			Edge next = alis[now.to][i];

			int next_cost = now.cost + next.cost;

			// K만큼 차지 않았을 때, 아직 더 들어갈 수 있을 때
			if (dist[next.to].size() < K) {

				dist[next.to].push(next_cost);
				pq.push({ next.to, next_cost });

			}
			// 꽉 찼을 때
			else {

				if (dist[next.to].top() > next_cost) {
					dist[next.to].pop();
					dist[next.to].push(next_cost);

					pq.push({ next.to, next_cost });
				}

			}

		}

	}


}


int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		alis[from].push_back({ to, cost });
	}

	dijkstra(1);

	for (int i = 1; i <= N; i++) {
		if (dist[i].size() == K) cout << dist[i].top() << '\n';
		else cout << -1 << '\n';
	}


	return 0;
}