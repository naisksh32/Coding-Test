#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
int table[1001][1001];
int dp[1001][1001];

int main() {
	cin >> N >> M;

	int max_size = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char c;
			cin >> c;
			table[i][j] = int(c - '0');

			if (table[i][j] == 1) {
				dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;

				max_size = max(max_size, dp[i][j]);
			}
		}
	}

	cout << max_size * max_size;
	return 0;
}