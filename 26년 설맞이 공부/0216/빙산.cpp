#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int board[301][301];
int visited[301][301];

struct Pos {
	int y, x;
};

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void turn() {
	int tmp_board[301][301] = { 0 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (board[i][j] != 0) {
				int zero_area = 0;

				for (int d = 0; d < 4; d++) {
					int ny = i + dy[d];
					int nx = j + dx[d];

					if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;

					if (board[ny][nx] == 0) zero_area++;
				}

				tmp_board[i][j] = board[i][j] - zero_area;
				if (tmp_board[i][j] < 0) tmp_board[i][j] = 0;
				
			}

		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] = tmp_board[i][j];
		}
	}

}

int bfs() {
	memset(visited, 0, sizeof(visited));
	int conti = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (board[i][j] != 0 && visited[i][j] == 0) {
				conti++;

				queue<Pos> q;
				q.push({ i, j });
				visited[i][j] = conti;

				while (!q.empty()) {
					Pos now = q.front();
					q.pop();

					for (int d = 0; d < 4; d++) {
						int ny = now.y + dy[d];
						int nx = now.x + dx[d];

						if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;
						if (board[ny][nx] == 0) continue;
						if (visited[ny][nx] != 0) continue;

						visited[ny][nx] = conti;
						q.push({ ny, nx });

					}
				}

			}

		}
	}

	return conti;
}

void print_board() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void print_visited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int t = 0;
	int c = bfs();
	while (c == 1) {
		turn();
		t++;
		c = bfs();

		//cout << "=== 현재 턴: " << t << " ===" << endl;
		//cout << "=== 현재 보드 현황 ===" << endl;
		//print_board();
		//cout << "=== 현재 대륙 현황 ===" << endl;
		//print_visited();
	}

	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] != 0) flag = true;
		}
	}

	(flag) ? cout << t : cout << 0;

	return 0;
}
