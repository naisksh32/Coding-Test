#include <iostream>
#include <cstring>
using namespace std;

int ans;

int board[10][10];

int papers[5];
int rest_1;

// 초기화 함수
void init() {
	ans = 21e8;
	rest_1 = 0;
	memset(papers, 0, sizeof(papers));
}

// 인풋 함수
void input() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) rest_1++;
		}
	}
}

// DFS로 색종이를 두는 경우를 탐색
void dfs(int y, int x) {

	// 시작 지점부터 탐색 진행
	for (int i = y; i < 10; i++) {
		for (int j = (i == y ? x : 0); j < 10; j++) {

			// 색종이를 둘 수 있으면
			if (board[i][j] == 1) {
				

				// 5, 4, 3, 2, 1 순으로 놓을 수 있는지 비교
				for (int d = 4; d >= 0; d--) {
					// 이미 색종이를 모두 사용했으면 pass
					if (papers[d] >= 5) continue;
					// 경계를 넘어갔으면 pass
					if (i + d >= 10 || j + d >= 10) continue;

					bool flag = true;

					// 한칸씩 색종이를 놓을 수 있는지 비교
					for (int dy = i; dy <= i + d; dy++) {
						for (int dx = j; dx <= j + d; dx++) {
						
							// 중간에 0이 발견되면 그 즉시 종료
							if (board[dy][dx] == 0) {
								flag = false;
								break;
							}

						}
						if (!flag) break;
					}

					// 만약 색종이를 둘 수 있다면
					if (flag) {

						// 들어가기 전
						for (int dy = i; dy <= i + d; dy++) {
							for (int dx = j; dx <= j + d; dx++) {
								board[dy][dx] = 0;
							}
						}
						papers[d]++;	// 색종이 수 증가
						rest_1 -= (d + 1) * (d + 1);

						// 재귀
						dfs(i, j);

						// 나온 후
						for (int dy = i; dy <= i + d; dy++) {
							for (int dx = j; dx <= j + d; dx++) {
								board[dy][dx] = 1;
							}
						}
						papers[d]--;	// 색종이 수 감소
						rest_1 += (d + 1) * (d + 1);
					}
				}

				return;
			}

		}
	}
	
	// 사용한 색종이 수 정산
	int paper = 0;
	for (int i = 0; i < 5; i++) {
		paper += papers[i];
	}

	// 모든 칸을 다 채웠을 때
	if (rest_1 == 0) {
		ans = min(ans, paper);
	}
}

void solve() {

	dfs(0, 0);
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		input();
		solve();

		cout << '#' << t << ' ';
		(ans != 21e8) ? cout << ans << '\n' : cout << -1 << '\n';
	}


	return 0;
}