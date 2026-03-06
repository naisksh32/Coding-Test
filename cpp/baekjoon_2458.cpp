#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool nxt[505][505];


int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;

		nxt[from][to] = true;
	}

	for (int t = 1; t <= N; t++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {

				if (nxt[i][t] && nxt[t][j]) nxt[i][j] = true;

			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		bool flag = true;

		for (int j = 1; j <= N; j++) {
			if (i == j) continue;

			if (!(nxt[i][j] || nxt[j][i])) flag = false;
		}

		if (flag) ans++;

	}

	cout << ans;

}