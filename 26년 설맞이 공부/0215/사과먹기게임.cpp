#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int ans;
int N;
int board[11][11];
int visited[11][11];

// 좌표를 저장할 구조체
struct Pos {
	int y, x;
};
Pos tar[11];

// 이동 정보를 저장할 배열들
char dir[4] = { 'U', 'D', 'L', 'R' };
struct Direction {
	Pos next;
	char path;
};
Direction direction[4][2] = {
	{{{-1, 0}, 'U'}, {{0, 1}, 'R'}},	// 상
	{{{1, 0}, 'D'}, {{0, -1}, 'L'}},	// 하
	{{{0, -1}, 'L'}, {{-1, 0},'U'}},	// 좌
	{{{0, 1}, 'R'}, {{1, 0}, 'D'}}	// 우
};
char end_dir;



void init() {
	ans = 0; 
	N = 0;
	memset(board, 0, sizeof(board));
	memset(tar, 0, sizeof(tar));
	tar[0] = { 0, 0 };
	end_dir = 'R';
}
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
}


int bfs(Direction start, Pos end) {
	// 방문 배열 초기화
	memset(visited, 0, sizeof(visited));

	// 현재 입력값을 큐에다 푸쉬
	queue <pair<Direction, int>> q;
	q.push({ start, 0 });
	
	// 목표 지점에 다다를때까지 큐를 통한 탐색 진행
	while (!q.empty()) {
		pair<Direction, int> now = q.front();
		q.pop();
		
		// 만약 현 지점이 도착지점이면, 이동한 칸수를 반환
		if (now.first.next.y == end.y && now.first.next.x == end.x) {
			end_dir = now.first.path;
			return now.second;
		}

		int idx = 0;
		for (int i = 0; i < 4; i++) {
			if (dir[i] == now.first.path) idx = i;
		}

		for (int d = 0; d < 2; d++) {
			int ny = now.first.next.y + direction[idx][d].next.y;
			int nx = now.first.next.x + direction[idx][d].next.x;

			if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;

			int is_trun = 0;
			if (d == 1) is_trun = 1;

			q.push({ {{ny, nx}, direction[idx][d].path}, now.second+is_trun });
		}

	}
}

void solve() {
	int max_apple = 0;
	// 보드판을 순회해서 목표 지점 설정
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 0) {
				tar[board[i][j]] = { i, j };
				max_apple = max(max_apple, board[i][j]);
			}
		}
	}

	// 주어진 사과 갯수대로 진행
	for (int apple = 0; apple < max_apple; apple++) {
		Pos start = tar[apple];
		Pos en = tar[apple+1];

		Direction st;
		if (apple == 0) {
			st = { start, 'R' };
		}
		else {
			st = { start, end_dir };
		}

		ans += bfs(st, en);

		//cout << ans << endl;
	}

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

/*
1
5
0 0 0 0 0
0 0 0 3 0
0 1 0 0 0
0 0 2 0 0
0 0 0 0 0
*/