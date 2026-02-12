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
	bool is_drop;
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
vector<Route> route2;

int dfs_max_length = 0;

void init(){
	// 변수 초기화
	N = 0; K = 0; max_height = 0;
	// 보드 초기화
	memset(board, 0, sizeof(board));
	route2.clear();
	dfs_max_length = 0;
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



//int bfs(int y, int x) {
//	// 방문 배열 초기화
//	memset(visited, 0, sizeof(visited));
//	// 큐
//	queue<Pos> q;
//	// 이번 탐색의 최장길이
//	int max_length = 0;
//
//	// 처음값 처리
//	visited[y][x] = 1;
//	q.push({ y, x, true});
//
//	// 큐가 빌 때까지 탐색
//	while (!q.empty()) {
//		// 현재값
//		Pos now = q.front(); q.pop();
//
//		bool is_drop = now.is_drop;
//		for (int d = 0; d < 4; d++) {
//			int ny = now.y + dy[d];
//			int nx = now.x + dx[d];
//
//			// 경계점 구분
//			if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;
//			// 이미 방문 했으면
//			if (visited[ny][nx] != 0) continue;
//
//			// 만약 기존보다 같거나 큰 값을 만났을 경우
//			if (board[now.y][now.x] <= board[ny][nx]) {
//
//				// 만약 깎을 권리가 없다면 pass - 이게 조건 추가 전 원래 로직
//				if (!is_drop) continue;
//				// =======================================================
//				// ▼ 산 깎기 로직
//				// 다음 산의 높이
//				int next_height = board[ny][nx];
//
//				// 깎아도 다음 연결이 계속 높다면, 이 칸은 이동 불가능
//				if (board[now.y][now.x] <= next_height - K) continue;
//
//				// 깎아서 이동했다면, 깎는 권한을 off
//				is_drop = false;
//			}
//
//			// 다음 값으로 처리
//			visited[ny][nx] = visited[now.y][now.x] + 1;
//			max_length = max(max_length, visited[ny][nx]);
//			q.push({ ny, nx, is_drop });
//		}
//
//	}
//
//	// 디버깅용
//	cout << "=== ( " << y << ", " << x << " ) ===" << endl;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cout << visited[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	// 최장 길이를 반환
//	return max_length;
//}

void show_visited() {
	cout << "===========" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}

int dfs(int y, int x, bool drop) {
	// 기저 - 더 이상 갈 곳이 없을 때
	
	// 현재 좌표의 정보
	Pos now = { y, x, drop };
	dfs_max_length = max(dfs_max_length, visited[y][x]);

	// 다음 좌표로 뻗어 나가기
	for (int d = 0; d < 4; d++) {
		int ny = now.y + dy[d];
		int nx = now.x + dx[d];

		// 경계점 구분
		if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;
		// 이미 방문 했으면
		if (visited[ny][nx] != 0) continue;

		// 다음칸이 더 높은 산이면서 깎을 수 있는 경우
		if (board[now.y][now.x] <= board[ny][nx]) {
			if (now.is_drop) {
				
				bool do_it = true;
				int temp_k = 0;
				// 최대 땅을 팔 수 있을 만큼 진행
				for (int k = 1; k <= K; k++) {

					// 일단은 파
					temp_k = k;
					board[ny][nx] -= k;

					// 그래도 높으면 다음 사이즈로 땅을 파서 진행
					if (board[now.y][now.x] <= board[ny][nx]) {
						
						// 근데 만약에 다 팠는데도? 이동을 할 수 없네??
						if (k == K) {
							do_it = false;
						}

						board[ny][nx] += k;
						continue;
					}

					break;
				}
				// 만약 산을 깎아도, 기존보다 높은 높이면 이건 안된다.
				if (!do_it) continue;

				visited[ny][nx] = visited[now.y][now.x] + 1;
				//show_visited();

				dfs(ny, nx, false);
				board[ny][nx] += temp_k;
				visited[ny][nx] = 0;
			}
			// 더 이상 뚫을 수도 없고, 이동할 수 없는 경우 pass
			else {
				continue;
			}
		}
		// 낮은 산이거나 깎을 수 없는 경우 - 정상 진행
		else {
			visited[ny][nx] = visited[now.y][now.x] + 1;
			//show_visited();

			dfs(ny, nx, now.is_drop);
			visited[ny][nx] = 0;
		}

	}
	return dfs_max_length;
}

void solve() {
	// 모든 칸을 순회하며, 최고점에서 BFS 시작
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == max_height) {
				//int length = bfs(i, j);

				//route.push_back({ i, j, length });
				memset(visited, 0, sizeof(visited));
				visited[i][j] = 1;
				int length2 = dfs(i, j, true);
				route2.push_back({ i, j, length2 });
			}

		}

	}

	//sort(route.begin(), route.end());
	sort(route2.begin(), route2.end());

}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		input();
		solve();

		//cout << '(' << route2[0].y << ", " << route2[0].x << ')' << endl;
		cout <<'#'<<t<<' '<< route2[0].length << '\n';
	}
	return 0;
}

/*
1
5 1
9 3 2 3 2
6 3 1 7 5
3 4 8 9 9
2 3 7 7 7
7 6 5 5 8

1
3 2
1 2 1
2 1 2
1 2 1

*/