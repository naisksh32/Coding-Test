#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int ans;
int N;
string board[301];
int visited[301][301];

int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

struct Node {
	int y;
	int x;
};

void init() {
	memset(visited, -1, sizeof(visited));
}
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
}


// 현재 좌표를 기준으로 8방향 탐색해서 주변에 있는 지뢰의 갯수를 반환
int find_mine(int y, int x) {
	int mine = 0;
	for (int d = 0; d < 8; d++) {
		int ny = y + dy[d];
		int nx = x + dx[d];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

		if (board[ny][nx] == '*') mine++;
	}
	return mine;
}

void BFS(int y, int x) {
	queue<Node> q;
	q.push({y, x});

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int d = 0; d < 8; d++) {
			int ny = now.y + dy[d];
			int nx = now.x + dx[d];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (visited[ny][nx] != -1) continue;
			
			int mine = find_mine(ny, nx);
			visited[ny][nx] = mine;
			if (mine == 0) q.push({ ny, nx });
		}
	}
}

void solve() {
	ans = 0;

	// 먼저 주변에 지뢰가 없는 지점을 먼저 탐색
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 현재 탐색 좌표가 지뢰이면 탐색 취소
			if (board[i][j] == '*') continue;
			if (visited[i][j] != -1) continue;

			int mine = find_mine(i, j);
			if (mine != 0) continue;
			
			visited[i][j] = mine;
			BFS(i, j);
			ans++;
		}
	}

	// 나머지 빈칸 탐색
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == '*') continue;
			if (visited[i][j] != -1) continue;

			int mine = find_mine(i, j);
			visited[i][j] = mine;
			ans++;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		input();
		solve();
		cout << '#' << t << ' ' << ans << '\n';
	}
	return 0;
}