#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;


int N, M;
int board[8][8];
int visited[8][8];

struct Pos {
	int y, x;
};
vector<Pos> virus;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int max_safe_zone;

int BFS() {
	memset(visited, 0, sizeof(visited));

	queue<Pos> q;
	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
		visited[virus[i].y][virus[i].x] = 1;
	}

	while(!q.empty()){
		Pos now = q.front(); q.pop();

		for (int d = 0; d < 4; d++) {
			int ny = now.y + dy[d];
			int nx = now.x + dx[d];

			if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;
			if (board[ny][nx] != 0) continue;
			if (visited[ny][nx] != 0) continue;

			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}

	int safe_zone = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0 && visited[i][j] == 0) safe_zone++;
		}
	}

	return safe_zone;
}

void DFS(int wall) {
	// 기저: 벽을 3개 세웠다면 진행
	if (wall >= 3) {
		//cout << "--------------------" << endl;
		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < M; j++) {
		//		cout << board[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		// BFS로 바이러스를 퍼트림 & 안전 구역값을 return
		int s = BFS();
		max_safe_zone = max(max_safe_zone, s);

		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			// 빈 칸인 경우에만 벽을 세울 수 있음
			if (board[i][j] == 0) {
				// 진입
				board[i][j] = 1;
				
				// 재귀
				DFS(wall + 1);

				// 복구
				board[i][j] = 0;
			}

		}
	}
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];

			if (board[i][j] == 2) virus.push_back({ i, j });

		}
	}

	DFS(0);

	// DFS로 벽을 치는 모든 경우의 수를 파악
	// BFS로 바이러스가 퍼지는 경우를 파악
	// 이후 남은 칸을 반환

	cout << max_safe_zone;
	return 0;
}