#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

// 정답
int ans;

// 움직이는 횟수, 충전기 대수
int turn, BC_cnt;

// 움직임 (y, x)
pair<int, int> ch_move[5] = {
	{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};
// A, B의 움직임
int A_move[101];
int B_move[101];

// 위치 좌표 구조체
struct Pos {
	int y, x;
};

// 충전기의 정보를 담는 구조체
struct Charge {
	Pos pos;
	int range;	// 1~4
	int power;	// 10~500, 짝수

	bool operator <(Charge right)const {
		if (power < right.power) return true;
		if (power > right.power) return false;
		return false;
	}
};
Charge BC[8];

struct CH {
	Pos pos;			// 현재의 위치 좌표
	int now_charge;		// 현재의 충전값
	int total_charge;	// 누적 충전값
};
// A,B 순서, index: 이동시간, value: 그때의 충전 값
CH history[2][101];

// 초기화 로직
void init() {
	ans = 0; turn = 0; BC_cnt = 0;
	memset(A_move, 0, sizeof(A_move));
	memset(B_move, 0, sizeof(B_move));
	memset(BC, 0, sizeof(BC));
	memset(history, 0, sizeof(history));
}
// 입력 로직
void input() {
	// 이동 턴수, 충전기 대수 입력
	cin >> turn >> BC_cnt;
	
	// A와 B의 이동좌표 입력
	for (int i = 0; i < turn; i++) cin >> A_move[i];
	for (int i = 0; i < turn; i++) cin >> B_move[i];

	// 충전기 정보 입력
	for (int i = 0; i < BC_cnt; i++) {
		cin >> BC[i].pos.x >> BC[i].pos.y >> BC[i].range >> BC[i].power;
	}

	// 충전기를 power 오름차순으로 정렬
	sort(BC, BC + BC_cnt);
}

// 멘헤튼 거리 계산식
int cal_dist(Pos pos, Pos charger) {
	return abs(pos.y - charger.y) + abs(pos.x - charger.x);
}

// 풀이 함수
void solve() {
	// 초기 A와 B의 좌표
	history[0][0].pos = { 1, 1 };
	history[1][0].pos = { 10, 10 };

	// 턴마다 이동하는 로직을 좌표에 추가
	for (int t = 0; t < turn; t++) {
		int Ady = ch_move[A_move[t]].first;
		int Adx = ch_move[A_move[t]].second;
		history[0][t + 1].pos = { history[0][t].pos.y + Ady, history[0][t].pos.x + Adx };

		int Bdy = ch_move[B_move[t]].first;
		int Bdx = ch_move[B_move[t]].second;
		history[1][t + 1].pos = { history[1][t].pos.y + Bdy, history[1][t].pos.x + Bdx };
	}

	// turn동안 이동 여부를 확인
	for (int t = 0; t <= turn; t++) {

		// A와 B에 대해서 충전할 수 있는 여부
		bool is_charge[2][8] = { false };

		// 현재 A와 B에 대해서 충전 여부를 파악
		for (int i = 0; i < 2; i++) {
			// 각 충전기마다 반복
			for (int j = 0; j < BC_cnt; j++) {
				// 만약 충전할 수 있는 범위 안이라면, 충전할 수 있다고 표시
				if (cal_dist(history[i][t].pos, BC[j].pos) <= BC[j].range) {
					is_charge[i][j] = true;
				}
			}
		}

		int max_sum = 0;

		for (int a = -1; a < BC_cnt; a++) {
			for (int b = -1; b < BC_cnt; b++) {
				int charge_A = 0;
				int charge_B = 0;

				if (a != -1 && is_charge[0][a]) charge_A = BC[a].power;
				if (b != -1 && is_charge[1][b]) charge_B = BC[b].power;

				int current_sum = 0;
				if (a != -1 && a == b && is_charge[0][a] && is_charge[1][b]) {
					current_sum = BC[a].power;
				}
				else {
					current_sum = charge_A + charge_B;
				}

				max_sum = max(max_sum, current_sum);
			}
		}

		if (t > 0) {
			history[0][t].total_charge = history[0][t - 1].total_charge + max_sum;
		}
		else {
			history[0][t].total_charge = max_sum;
		}
	}
	ans = history[0][turn].total_charge;
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
