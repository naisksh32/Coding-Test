#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int ans;

int N, M;
int S, D;

struct Edge {
	int to;
	int cost;
	bool is_short = false;

	bool operator<(Edge right)const {
		if (cost > right.cost) return true;
		if (cost < right.cost) return false;
		return false;
	}
};
vector<Edge> alis[501];
int dist[501];

vector<int> path[501];
// 간선이 지워졌는지, 그리고 방문했는지 확인
bool dropped[501][501];



void init() {
	for (int i = 0; i < 501; i++) {
		alis[i].clear();
		path[i].clear();
	}
	memset(dropped, false, sizeof(dropped));
}
void input() {
	cin >> S >> D;
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		alis[from].push_back({ to, cost });
	}
}


// 재귀 함수로 경로 역추적
void trackback(int node) {

	// 시작노드에 도달하면 종료
	if (node == S) return;


	for (int i = 0; i < path[node].size(); i++) {
		int pre_node = path[node][i];
		
		// 이미 제거했다고 하면 pass
		if (dropped[pre_node][node]) continue;

		// 해당 가는 노드는 사용하지 않음
		dropped[pre_node][node] = true;

		trackback(pre_node);
	}
}



void dijkstra(int st, int ed) {
	for (int i = 0; i <= N; i++) {
		dist[i] = 21e8;
	}

	priority_queue<Edge> pq;
	pq.push({ st, 0 });
	dist[st] = 0;


	while (!pq.empty()) {
		Edge now = pq.top(); pq.pop();
		if (dist[now.to] < now.cost) continue;

		for (int i = 0; i < alis[now.to].size(); i++) {
			Edge next = alis[now.to][i];

			// 삭제된 간선인지 확인
			if (dropped[now.to][next.to]) continue;
			
			int next_cost = dist[now.to] + next.cost;

			if (dist[next.to] > next_cost) {

				path[next.to].clear();
				path[next.to].push_back(now.to);

				dist[next.to] = next_cost;
				pq.push({ next.to, next_cost });
			}
			else if (dist[next.to] == next_cost) {
				path[next.to].push_back(now.to);
			}
		}
	}
}



void solve() {
	dijkstra(S, D);
	trackback(D);
	dijkstra(S, D);
	
	if (dist[D] != 21e8) ans = dist[D];
	else ans = -1;
}

int main() {
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;

		init();
		input();
		solve();

		cout << ans << '\n';
	}

}