#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int ans;
int N, M;
char board[110][110];

struct Pos {
	int y, x;
};
vector<Pos> ch;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

struct Node {
	int y, x;
	int door;

	bool operator<(Node right)const {
		if (door > right.door) return true;
		if (door < right.door) return false;
		return false;
	}
};
int dist[3][110][110];

int total_dist[110][110];



void init() {
	ch.clear();
	for (int i = 0; i < 110; i++) {
		for (int j = 0; j < 110; j++) {
			total_dist[i][j] = 10001;
		}
	}
}

void input() {
	ch.push_back({ 0, 0 });
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
			if (board[i][j] == '$') ch.push_back({ i, j });
		}
	}

	for (int i = 0; i < N + 2; i++) {
		board[i][0] = '.';
		board[i][M + 1] = '.';
	}
	for (int j = 0; j < M + 2; j++) {
		board[0][j] = '.';
		board[N + 1][j] = '.';
	}

}

void dijkstra(int idx, Pos pos) {
	// 거리 배열 초기화
	for (int i = 0; i <N+2; i++) {
		for (int j = 0; j <= M+2; j++) {
			dist[idx][i][j] = 10001;
		}
	}

	priority_queue<Node> pq;
	pq.push({ pos.y, pos.x, 0 });
	dist[idx][pos.y][pos.x] = 0;

	while (!pq.empty()) {
		Node now = pq.top(); pq.pop();

		for (int d = 0; d < 4; d++) {
			int ny = now.y + dy[d];
			int nx = now.x + dx[d];

			if ( ny < 0 || ny >= N+2 || nx < 0 || nx >= M+2 ) continue;
			if (board[ny][nx] == '*') continue;
		
			int next_door = now.door;
			if (board[ny][nx] == '#') {
				next_door++;
			}

			if (dist[idx][ny][nx] <= next_door) continue;

			dist[idx][ny][nx] = next_door;
			pq.push({ ny, nx, next_door });
		}
	}
}

void solve() {
	// 각 구성원 별 모든 칸을 탐색
	for (int i = 0; i < 3; i++) {
		dijkstra(i, ch[i]);
	}

	int min_door = 10001;
	for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < M + 2; j++) {
			if (board[i][j] == '*') continue;

			if (dist[0][i][j] == 10001 || dist[1][i][j] == 10001 || dist[2][i][j] == 10001) continue;
			
			total_dist[i][j] = dist[0][i][j] + dist[1][i][j] + dist[2][i][j];
			if (board[i][j] == '#') total_dist[i][j] -= 2;

			min_door = min(min_door, total_dist[i][j]);
		}
	}

	ans = min_door;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		init();
		input();
		solve();

		cout << ans << '\n';
	}
}