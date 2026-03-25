#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, S, T;
int Q;

int roads[301][301];


void show() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << roads[i][j] << ' ';
		}
		cout << '\n';
	}
}

void fluid() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {

				if (i == j) continue;
				roads[i][j] = min(roads[i][k] + roads[k][j], roads[i][j]);

			}
		}
	}
}

int main() {
	cin >> N >> M >> S >> T;

	// 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) roads[i][j] = 0;
			else roads[i][j] = 1e9;
		}
	}

	// 입력
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		roads[from][to] = cost;
	}
	

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a1, b1, c1, a2, b2, c2;
		cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

		roads[a1][b1] = c1;
		roads[a2][b2] = c2;
		
		fluid();
		cout << roads[S][T] << '\n';

		roads[a1][b1] = 1e9;
		roads[a2][b2] = 1e9;
	}

	return 0;
}