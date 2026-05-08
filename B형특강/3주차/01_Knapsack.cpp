#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int ans;

int N, K;
int dp[101][1001];
int weight[101];
int value[101];

void init() {
	memset(dp, 0, sizeof(dp));
	memset(weight, 0, sizeof(weight));
	memset(value, 0, sizeof(value));
}
void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> weight[i];
		cin >> value[i];
	}
}
void solve() {
	// DP 테이블 채우기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			
			if (j - weight[i] < 0) {
				dp[i][j] = dp[i - 1][j];
				continue;
			}

			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
		}
	}

	ans = dp[N][K];
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

}