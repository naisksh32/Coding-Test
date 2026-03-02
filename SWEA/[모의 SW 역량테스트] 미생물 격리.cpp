#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int ans;

// 보드 가로세로(N), 시간(M), 군집 수(K)
int N, M, K;

// 미생물 군집 수랑, 방향을 가지는 구조체
struct mm {
	int size;
	int dir;
	int pre;
};

// 다룰 보드판
mm board[101][101];

// 상(1), 하(2), 좌(3), 우(4)
int dy[] = { 0, -1, 1, 0, 0 };
int dx[] = { 0, 0, 0, -1, 1 };


void init() {
	ans = 0; N = 0; M = 0; K = 0;
	memset(board, 0, sizeof(board));
}
void input() {
	cin >> N >> M >> K;

	for (int k = 0; k < K; k++) {
		int y, x;
		cin >> y >> x;
		cin >> board[y][x].size >> board[y][x].dir;
	}
}


// 임시 저장할 임시 보드
mm temp_board[101][101];

void solve() {
	// 주어진 시간동안 움직임
	int time = 0;
	while (time < M) {
		
		// 임시 보드 초기화
		memset(temp_board, 0, sizeof(temp_board));

		// 전체를 순환하며 군집이 있는 경우 움직임을 진행
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j].size != 0) {
					// 군집의 크기 저장
					int s = board[i][j].size;
					// 군집의 이동 방향
					int d = board[i][j].dir;
					int ny = i + dy[d];
					int nx = j + dx[d];

					// 이동을 할 예정이니 기존 board의 값은 0으로 초기화
					//board[i][j].size = 0; board[i][j].dir = 0;

					// 이동한 좌표가 경계점인 경우!
					if (ny == 0 || ny == N - 1 || nx == 0 || nx == N - 1) {
						// 군집의 크기는 절반의 크기로 줄어들음
						s /= 2;

						// 방향은 정 반대로 바뀜
						if (d == 1) d = 2;		else if (d == 2) d = 1;
						else if (d == 3) d = 4; else if (d == 4) d = 3;
					}
					
					// 이동한 좌표에 군집을 더함
					temp_board[ny][nx].size += s;
					
					// 더해진 군집 중에서 더 큰 군집이 있다면 방향을 갱신
					if (temp_board[ny][nx].pre < s) {
						temp_board[ny][nx].dir = d;
						temp_board[ny][nx].pre = max(temp_board[ny][nx].pre, s);
					}

				}
			}
		}
		// 임시 보드의 내용을 반영
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				board[i][j] = temp_board[i][j];
			}
		}

		// 기존 최댓값을 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				board[i][j].pre = 0;
			}
		}

		// 시간 +1
		time++;
	}

	// 남아있는 미생물의 합 구하기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += board[i][j].size;
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
