#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, S, T;
int Q;

long long roads[301][301];


void show() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << roads[i][j] << ' ';
		}
		cout << '\n';
	}
}


int main() {

	// 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> S >> T;

	// 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) roads[i][j] = 0;
			else roads[i][j] = 1e15;
		}
	}

	// 입력
	for (int i = 0; i < M; i++) {
		int from, to;
		long long cost;

		cin >> from >> to >> cost;

		roads[from][to] = min(cost, roads[from][to]);
	}
	
	// 플루이드-워셜
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {

				if (i == j) continue;
				roads[i][j] = min(roads[i][k] + roads[k][j], roads[i][j]);

			}
		}
	}

	//show();

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a1, b1, c1, a2, b2, c2;
		cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
		
		long long ans = roads[S][T];

		ans = min(ans, roads[S][a1] + c1 + roads[b1][T]);
		ans = min(ans, roads[S][a2] + c2 + roads[b2][T]);
		ans = min(ans, roads[S][a1] + c1 + roads[b1][a2] + c2 + roads[b2][T]);
		ans = min(ans, roads[S][a2] + c2 + roads[b2][a1] + c1 + roads[b1][T]);

		if (ans >= 1e15) cout << -1 << '\n';
		else cout << ans << '\n';

	}

	return 0;
}