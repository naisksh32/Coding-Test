#include <iostream>
using namespace std;

int ans;		// 정답

int N;			// 배수
int mask;		// 0~9 정답지
int my_note;	// 내가 기록할 답안지

// 초기화
void init() {
	mask = (1 << 10) - 1;
	my_note = 0;
}

// 인풋
void input() {
	cin >> N;
}

// 풀이
void solve() {
	int cnt = 0;

	// 모든 숫자(0~9)까지 채울때 까지 while문을 통해 반복
	while (true) {
		cnt++;				// 반복 횟수 증가
		int k = cnt;		// 배수 설정
		int num = k * N;	// 타겟 수 설정

		// 각 자리수 분별 후 my_note에 기록
		while (num > 0) {
			int left = num % 10;				// 끝 자릿수 추출
			my_note = my_note | (1 << left);	// my_note에 수 기록
			num /= 10;							// 이후 한단계 앞당김
		}

		// 모든 자릿수를 채웠는지 판별
		if (my_note == mask) break;
	}

	// 마지막으로 본 수 기록
	ans = cnt * N;
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