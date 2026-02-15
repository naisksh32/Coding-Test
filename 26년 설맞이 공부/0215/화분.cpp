#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int ans;	// 정답
int case_h;	// 각 케이스별 임시 높이
int N, p;	// 화분의 갯수, 더블 성장 유무
int A[21];	// A 비료 성장
int B[21];	// B 비료 성장

// 초기화 함수
void init(){
	ans = 0;
	N = 0; p = 0;
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
}

// 입력 함수
void input() {
	// 화분 갯수, 더블 성장력
	cin >> N >> p;
	// A 비료 성장력
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	// B 비료 성장력
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
}


void dfs(int pot, int pre) {
	// 기저
	// 주어진 화분의 갯수에 모두 비료를 채웠으면 종료
	if (pot >= N) {
		// 최고 높이를 갱신
		ans = max(ans, case_h);
		return;
	}

	// 재귀
	// A넣을까? B 넣을까?
	for (int i = 0; i < 2; i++) {
		
		// A 비료를 넣는 경우
		if (i == 0) {
			int grow = A[pot];
			// 만약 이전에 A비료를 넣었을 경우
			// 더블 성장력 만큼 성장력 감소
			if (pre == 0) grow -= p;

			case_h += grow;
			dfs(pot + 1, 0);
			case_h -= grow;
		}
		// B 비료를 넣는 경우
		else if (i == 1) {
			int grow = B[pot];
			// 만약 이전에 B비료를 넣었을 경우
			// 더블 성장력 만큼 성장력 감소
			if (pre == 1) grow -= p;

			case_h += grow;
			dfs(pot + 1, 1);
			case_h -= grow;

		}
	}

}

// 풀이 함수
void solve() {
	// 케이스 별 높이 초기화
	case_h = 0;
	// DFS로 각 화분의 비료 선택
	dfs(0, -1);
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
4 2
4 2 6 4
5 6 4 1
*/
// 18