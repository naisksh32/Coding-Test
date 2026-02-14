#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;


int N;			// 나무의 갯수
int trees[101];	// 나무의 높이 정보
int ans = 0;

void init() {
	N = 0; ans = 0;
	memset(trees, 0, sizeof(trees));
}
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
	}
}

void solve() {
	// 트리의 최고 높이 구하기
	int max_h = 0;
	for (int i = 0; i < N; i++) {
		max_h = max(max_h, trees[i]);
	}

	int one = 0;	// 필요 1의 갯수 (홀수 날짜)
	int two = 0;	// 필요 2의 갯수 (짝수 날짜)

	// 각 나무별 필요한 1과 2의 갯수 파악
	for (int i = 0; i < N; i++) {
		// 최고 나무 높이에서 현재 나무 높이 빼기
		int diff = max_h - trees[i];
		// 만약 차이가 없다면 다음 나무로
		if (diff == 0) continue;

		two += diff / 2;	// 차이의 2의 몫
		one += diff % 2;	// 차이의 2의 나머지
	}

	// 2가 너무 많으면 1, 1로 쪼개서 분배 - Greedy
	// 1, 2, 1, 2, ...
	while (two > one + 1) {
		two -= 1;
		one += 2;
	}

	if (one > two) ans = one * 2 - 1;
	else ans = two * 2;

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
}