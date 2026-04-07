#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

# define INF 1e9;

int N;
int W[16][16];
int dp[16][1 << 16];


int dfs(int curr, int visited) {
	// 1. 기저
	if (visited == (1 << N) - 1) {
		if (W[curr][0] != 0) return W[curr][0];
		return INF;
	}

	// 2. 이미 저장해둔 경로라면
	if (dp[curr][visited] != -1) return dp[curr][visited];

	// 3. 탐색 시작
	dp[curr][visited] = INF;

	for (int i = 0; i < N; i++) {
		// 갈 수 없는 길이면 pass
		if (W[curr][i] == 0 || (visited & (1 << i))) continue;

		dp[curr][visited] = min(dp[curr][visited], W[curr][i] + dfs(i, visited | (1 << i)));
	}

	return dp[curr][visited];
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 1);

	return 0;
}