#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// 보드의 넓이(N), 최대 공사 가능 깊이(K)
int N, K;
int board[10][10];
int visited[10][10];
// 최대 높이
int max_height = 0;

// 방향배열
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

// 좌표 구조체
struct Pos {
	int y, x;
};

// 각 지점의 최장길이를 저장할 벡터
struct Route {
	int y, x;
	int length;

	bool operator<(Route right) const {
		if (length > right.length) return true;
		if (length < right.length) return false;
		return false;
	}
};
vector<Route> route;


void init(){
	// 변수 초기화
	N = 0; K = 0; max_height = 0;
	// 보드 초기화
	memset(board, 0, sizeof(board));
}
void input() {
	// 보드 넓이, 깊이 인풋
	cin >> N >> K;
	// 보드 정보 받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;
			board[i][j] = n;

			// 최대 높이 구하기
			max_height = max(max_height, n);
		}
	}
}

int bfs(int y, int x) {
	// 방문 배열 초기화
	memset(visited, 0, sizeof(visited));
	// 큐
	queue<Pos> q;
	// 이번 탐색의 최장길이
	int max_length = 0;

	// 처음값 처리
	visited[y][x] = 1;
	q.push({ y, x });

	// 큐가 빌 때까지 탐색
	while (!q.empty()) {
		// 현재값
		Pos now = q.front(); q.pop();

		for (int d = 0; d < 4; d++) {
			int ny = now.y + dy[d];
			int nx = now.x + dx[d];

			// 경계점 구분
			if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;
			// 이미 방문 했으면
			if (visited[ny][nx] != 0) continue;
			// 기존보다 반드시 낮은 값으로만 이동
			if (board[now.y][now.x] <= board[ny][nx]) continue;

			// 다음 값으로 처리
			visited[ny][nx] = visited[now.y][now.x] + 1;
			max_length = max(max_length, visited[ny][nx]);
			q.push({ ny, nx });
		}

	}
	return max_length;
}

void solve() {
	// 모든 칸을 순회하며, 최고점에서 BFS 시작
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == max_height) {
				int length = bfs(i, j);

				route.push_back({ i, j, length });
			}
		}
	}

	sort(route.begin(), route.end());

}

int main() {
	init();
	input();
	solve();
	cout << '(' << route[0].y << ", " << route[0].x << ')' << endl;
	cout << route[0].length;

	return 0;
}

/*
5 1
9 3 2 3 2
6 3 1 7 5
3 4 8 9 9
2 3 7 7 7
7 6 5 5 8
*/