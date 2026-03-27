#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, M, R;
int items[101];
int dist[101][101];


int main() {
	// 노드, 탐색범위, 엣지 수
	cin >> N >> M >> R;

	// 각 노드의 아이템 수
	for (int i = 1; i <= N; i++) {
		cin >> items[i];
	}
	
	// 거리 배열 큰 수로 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = 1e8;
		}
	}

	// 노드 정보를 인접 행렬로 받음
	for (int i = 0; i < R; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		
		// 양방향 연결
		dist[from][to] = cost;
		dist[to][from] = cost;
	}

	// 플루이드 워셜 - 거리 탐색
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	// 최대로 얻을 수 있는 아이템 수
	int max_item = 0;


	// 1번 노드부터 탐색해서 얻을 수 있는 최대 아이템 수 갱신
	for (int i = 1; i <= N; i++) {

		// i번 노드 탐색 시 얻을 수 있는 아이템 수
		int cur_item = 0;
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] <= M) {
				cur_item += items[j];
			}
		}

		// 최댓값 갱신
		max_item = max(max_item, cur_item);
	}

	cout << max_item << '\n';

	return 0;
}