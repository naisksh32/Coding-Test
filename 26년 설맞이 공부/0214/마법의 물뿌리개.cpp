#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// 나무의 갯수
int N;
int trees[101];	// 나무들의 높이
int max_height;	//최고 나무 높이
int min_day;	// 최저 날짜

// 초기화 함수
void init() {
	N = 0;
	memset(trees, 0, sizeof(trees));
	max_height = 0;
	min_day = 21e8;
}
// 입력 함수
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
		max_height = max(max_height, trees[i]);
	}
}


void dfs(int day, bool watered) {
	// 기저
	bool flag = true;
	for (int i = 0; i < N; i++) {
		if (trees[i] != max_height) {
			flag = false;
			break;
		}
	}
	// 모든 나무의 높이가 최고 나무의 높이랑 같다면
	// 최저 날짜를 반환하고 탈출
	if (flag) {
		min_day = min(min_day, day);
		return;
	}

	// 성장 크기 설정
	int grow;
	if (day % 2 == 0) grow = 1;
	else grow = 2;

	// 재귀
	// 각 나무마다 물을 줄지, 안줄지 브랜치 생성
	for (int tree = 0; tree < N; tree++) {
		// 가지치기	- 만약 해당 나무가 최대 높이보다 더 성장한다면 pass
		if (trees[tree]+grow > max_height) continue;

		// 2가지 경우의 수 - 물을 안뿌리거나, 뿌리거나
		for (int i = 0; i < 2; i++) {
			if (i == 0 && watered) {
				dfs(day + 1, false);
			}
			else {
				// 전처리
				trees[tree] += grow;

				// 재귀함수
				dfs(day + 1, true);

				// 복귀
				trees[tree] -= grow;

			}
		}
		
	}

}

void solve() {
	
	// 처음엔 안주고 pass 할 수 있으므로
	dfs(0, true);
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		input();
		solve();

		cout << '#' << t << ' ' << min_day << endl;
	}
	
	return 0;
}