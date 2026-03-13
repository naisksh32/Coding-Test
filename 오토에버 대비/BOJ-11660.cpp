#include <iostream>
using namespace std;

int N, M;
int board[1025][1025];
int dp[1025][1025];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + board[i][j];
		}
	}


	for (int ord = 0; ord < M; ord++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;


		int ans = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		cout << ans << '\n';
	}

	return 0;
}