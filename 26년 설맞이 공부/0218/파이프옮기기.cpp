#include <iostream>
#include <cstring>
using namespace std;

int ans;
int N;
int board[20][20];	// N은 3~16

int cnt = 0;

struct Pos {
	int y, x;
};

// 파이프 모양 = { 가로, 대각선, 세로 }
int pipe[3] = { 0, 1, 2 };

void init() {
	ans = 0; N = 0; cnt = 0;
	memset(board, -1, sizeof(board));
}
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
}

void DFS(Pos now, int pipe) {
	// 기저
	// 만약 현재 좌표가 목표 지점인 (N, N)에 도달 했다면
	// 경우를 1 증가하고 함수를 종료
	if (now.y == N && now.x == N) {
		cnt++;

		return;
	}

	// 재귀
	for (int p = 0; p < 3; p++) {
		// 다음방향 좌표 변수
		int ny, nx;

		// 가로 방향 파이프에서 연결 하려면
		if (pipe == 0) {
			// 가로-가로 연결
			if (p == 0) {
				ny = now.y;
				nx = now.x + 1;
			}
			// 가로-대각선 연결
			else if (p == 1) {
				ny = now.y + 1;
				nx = now.x + 1;

				if (board[ny - 1][nx] != 0) continue;
				if (board[ny][nx - 1] != 0) continue;
			}
			// 만약 가로-세로 연결이면 pass
			else if (p == 2) continue;
		}
		// 대각선 방향 파이프에서 연결 하려면
		else if (pipe == 1) {
			// 대각선-가로 연결
			if (p == 0) {
				ny = now.y;
				nx = now.x + 1;
			}
			// 대각선-대각선 연결
			else if (p == 1) {
				ny = now.y + 1;
				nx = now.x + 1;

				if (board[ny - 1][nx] != 0) continue;
				if (board[ny][nx - 1] != 0) continue;
			}
			// 대각선-세로 연결
			else if (p == 2) {
				ny = now.y + 1;
				nx = now.x;
			}
		}
		// 세로 방향 파이프에서 연결하려면
		else if (pipe == 2) {
			// 만약 세로-가로 연결이면 pass
			if (p == 0) continue;
			// 세로-대각선 연결
			else if (p == 1) {
				ny = now.y + 1;
				nx = now.x + 1;

				if (board[ny - 1][nx] != 0) continue;
				if (board[ny][nx - 1] != 0) continue;
			}
			// 세로-세로 연결
			else if (p == 2) {
				ny = now.y + 1;
				nx = now.x;
			}
		}

		if (ny >= N + 1 || ny < 1 || nx >= N + 1 || nx < 1) continue;
		if (board[ny][nx] == 1) continue;

		board[ny][nx] = 1;
		DFS({ ny, nx }, p);
		board[ny][nx] = 0;
	}
}

void solve() {
	int first_pipe = pipe[0];
	board[1][1] = 1;
	board[1][2] = 1;

	DFS({1, 2}, first_pipe);

	ans = cnt;
}


int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		input();
		solve();

		cout << '#' << t << ' ' << ans << endl;
	}
	return 0;
}
