#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int ans;			// 정답
int N;				// 보드의 가로 세로 길이
int board[31][31];	// 보드 정보
int fuel[31][31];	// 이동하면서 담을 연료 정보

// 상 하 좌 우 방향배열
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

// 좌표 정보 구조체
struct Pos {
	int y, x;
};
// 시작점 끝점 좌표 설정
Pos st = { 0, 0 };
Pos en = { N - 1, N - 1 };

// 초기화 함수
void init(){
	// 정답, N 초기화
	ans = 0; N = 0; 

	// 보드 정보 초기화
	memset(board, 0, sizeof(board));

	// 이동 연료 정보 초기화 - 최솟값을 구할 것이라 21e8 선택
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			fuel[i][j] = 21e8;
		}
	}

}

// 입력 함수
void input() {
	// 가로 세로 길이 인풋
	cin >> N;

	// 보드 정보 인풋
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
}


void bfs(Pos st) {
	// 큐 설정
	queue<Pos> q;
	q.push(st);
	// 시작지점은 연료가 0;
	fuel[st.y][st.x] = 0;

	while (!q.empty()) {
		// 현재 지점
		Pos now = q.front();
		q.pop();

		// 4방향 탐색
		for (int d = 0; d < 4; d++) {
			int ny = now.y + dy[d];
			int nx = now.x + dx[d];

			// 경계 체크
			if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;

			// 다음 경로 비용 체크
			int next_cost;
			// 내리막길인 경우
			if (board[now.y][now.x] > board[ny][nx]) {
				next_cost = 0;
			}
			// 오르막길인 경우
			else if (board[now.y][now.x] < board[ny][nx]) {
				next_cost = (board[ny][nx]- board[now.y][now.x]) * 2;
			}
			// 평지인 경우
			else if (board[now.y][now.x] == board[ny][nx]) {
				next_cost = 1;
			}

			// 만약 다음 이동하는 연료 소비가, 기존의 소비보다 클 경우 pass
			if (fuel[ny][nx] <= fuel[now.y][now.x] + next_cost) continue;

			// 연료 맵을 업데이트
			fuel[ny][nx] = fuel[now.y][now.x] + next_cost;

			// 큐에 다음 목적지를 push
			q.push({ ny, nx });
		}
	}
}

// 풀이 함수
void solve() {
	
	bfs(st);

	ans = fuel[N - 1][N - 1];
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