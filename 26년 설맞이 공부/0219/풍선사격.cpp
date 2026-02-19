#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


int ans;

int N;
int score;

int ballon[10];
bool used[10];

vector<int> path;

void init() {
	ans = 0; N = 0; score = 0;
	memset(ballon, 0, sizeof(ballon));
	memset(used, false, sizeof(used));
}
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ballon[i];
	}
}

void DFS(int rest) {
	// 기저
	if (rest == N) {
		ans = max(ans, score);

		//for (int i = 0; i < N; i++) {
		//	cout << path[i] << " ";
		//}
		//cout << ": " << score << " : " << ans;
		//cout << endl;
		return;
	}

	// 재귀
	for (int i = 0; i < N; i++) {

		// 해당 풍선이 이미 터진 경우는 pass
		if (used[i] == true) continue;

		// 점수 계산
		int s, ps, ns;
		int pi, ni;
		
		// 마지막 한개 남은 풍선을 터트릴 때;
		if (rest == N - 1) {
			s = ballon[i];
		}
		else {
			pi = i - 1;
			bool flag1 = true;
			if (pi < 0) {
				flag1 = false;
			}
			else {
				while (used[pi]) {
					pi--;
					if (pi < 0) flag1 = false;
				}
			}

			ni = i + 1;
			bool flag2 = true;
			if (ni >= N) {
				flag2 = false;
			}
			else {
				while (used[ni]) {
					ni++;
					if (ni >= N) flag2 = false;
				}
			}

			ps = (flag1) ? ballon[pi] : 1;
			ns = (flag2) ? ballon[ni] : 1;

			s = ps * ns;
		}

		score += s;
		used[i] = 1;
		path.push_back(ballon[i]);

		//cout << "=== " << i << " ===" << endl;
		//if (rest != N - 1) {
		//	cout << '(' << pi << ", " << ni << ')' << endl;
		//	cout << ps << ", " << ns << " : " << s << endl;
		//}
		//else {
		//	cout << s << endl;
		//}

		DFS(rest + 1);

		score -= s;
		used[i] = 0;
		path.pop_back();
	}

}


void solve() {
	DFS(0);
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
4
1 2 3 4
*/