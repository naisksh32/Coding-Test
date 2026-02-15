#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int ans;

int N;			// 사람&모자 수
int human[501];	// 사람들이 원하는 모자 정보
int hat[501];	// 실제 모자 정보
int used[501];	// 모자의 사용 여부

int cnt;	// 모자를 착용한 사람의 수

// 초기화 함수
void init(){
	N = 0;
	memset(human, 0, sizeof(human));
	memset(hat, 0, sizeof(hat));
	memset(used, 0, sizeof(used));
	ans = 0;
}

// 입력 함수
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> human[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> hat[i];
	}
}


// 풀이 함수
void solve() {
	cnt = 0;

	// 오름차순 정렬
	sort(human, human + N);
	sort(hat, hat + N);

	// 모든 사람에 대해서, 모자에 대해 탐색
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (used[j] == 1) continue;

			// 원하는 사이즈 차이가 3이내인 경우
			if (abs(human[i] - hat[j]) <= 3) {
				// 해당 모자를 사용
				used[j] = 1;
				// 착용한 사람 +1
				cnt++;
				// 다음 사람 모자 탐색
				break;
			}

		}

	}
	ans = cnt;
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