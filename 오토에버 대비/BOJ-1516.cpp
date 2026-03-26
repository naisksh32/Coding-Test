#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int N;

int work[501];
int result[501];

vector<int> alis[501];
int dag[501];


int main() {
	// 입력
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int time;
		cin >> time;
		work[i] = time;

		while (1) {
			int pre;
			cin >> pre;
			
			if (pre == -1) break;

			alis[pre].push_back(i);
			dag[i]++;
		}
	}

	// 풀이
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		result[i] = work[i];
		if (dag[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i = 0; i < alis[cur].size(); i++) {
			int next = alis[cur][i];

			result[next] = max(result[next], result[cur] + work[next]);

			dag[next]--;

			if (dag[next] == 0) {
				work[next] += work[cur];
				q.push(next);
			}
		}
	}

	// 출력
	for (int i = 1; i <= N; i++) {
		cout << result[i] << '\n';
	}

	return 0;
}