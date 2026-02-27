#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int ans;

int N;
int node[20];
vector<int> path;
int max_score = 0;

int cal() {
	if (path.size() != 4) return -1;

	int A = node[path[0]]; int B = node[path[1]];
	int C = node[path[2]]; int D = node[path[3]];

	int s1 = pow((A + B), 2) + pow((C + D), 2);
	int s2 = pow((A + D), 2) + pow((B + C), 2);

	return max(s1, s2);
}

void dfs(int level, int idx) {
	if (level >= 4) {
		int score = cal();
		max_score = max(max_score, score);
		return;
	}

	for (int i = idx; i < N; i++) {
		// 만약 처음노드를 넣고, 마지막 노드를 선택할 때
		if (path.size() > 0 && path[0] == 0 && i == (N - 1)) continue;
		
		path.push_back(i);
		dfs(level + 1, i + 2);
		path.pop_back();
	}
}

void init() {
	memset(node, 0, sizeof(node));
	path.clear();
	max_score = 0;
}
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> node[i];
	}
}
void solve() {
	dfs(0, 0);
	ans = max_score;
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