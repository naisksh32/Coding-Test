#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


int M, N;
int board[1001][1001];
int visited[1001][1001];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

struct Pos {
	int y, x;
};
vector<Pos> tomato;
int max_date = 0;

void bfs() {
	queue<Pos> q;
	
	for(int i=0; i<tomato.size(); i++){
		q.push(tomato[i]);
		visited[tomato[i].y][tomato[i].x] = 0;
	}

	while (!q.empty()) {
		Pos now = q.front(); q.pop();

		for (int d = 0; d < 4; d++) {
			int ny = now.y + dy[d];
			int nx = now.x + dx[d];

			if (ny >= N || ny < 0 || nx >= M || nx < 0)continue;
			if (board[ny][nx] == -1) continue;
			if (visited[ny][nx] != -1) continue;

			visited[ny][nx] = visited[now.y][now.x] + 1;
			max_date = visited[ny][nx];
			q.push({ ny, nx });
		}
	}
}

int main() {
	cin >> M >> N;

	memset(board, 0, sizeof(board));
	memset(visited, -1, sizeof(visited));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];

			if (board[i][j] == 1) {
				tomato.push_back({ i, j });
			}
		}
	}


	bfs();

	bool flag = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] != -1) {
				if (visited[i][j] == -1) flag = false;
			}
		}
	}

	(flag) ? cout << max_date : cout << -1;

	return 0;
}