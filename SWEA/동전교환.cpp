#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int T, n;
int coin[10];
int cost[3001];

int main() {
	cin >> T >> n;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	for (int i = 0; i <= T; i++) {
		cost[i] = 21e8;
	}
	cost[0] = 0;
	for (int i = 0; i < n; i++) {
		cost[coin[i]] = 1;
	}

	for (int i = 0; i <= T; i++) {
		for (int c = 0; c < n; c++) {
			if (i - coin[c] <= 0) continue;

			cost[i] = min(cost[i], cost[i - coin[c]] + 1);
		}
	}

	if (cost[T] == 21e8) cout << "impossible";
	else cout << cost[T];

	return 0;
}