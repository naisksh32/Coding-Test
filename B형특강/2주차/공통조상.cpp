#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

pair<int, int> ans;
int V, E, tar1, tar2;

struct Node {
	int left;
	int right;
	int parent;
};

Node tree[10005];
bool visited[10005];

void init() {
	memset(tree, 0, sizeof(tree));
	memset(visited, 0, sizeof(visited));
}
void input() {
	cin >> V >> E >> tar1 >> tar2;

	for (int i = 0; i < E; i++) {
		int p, c;
		cin >> p >> c;

		if (tree[p].left == 0) {
			tree[p].left = c;
		}
		else {
			tree[p].right = c;
		}

		tree[c].parent = p;
	}
}

int count_subtree(int node) {
	if (node == 0) return 0;
	return 1 + count_subtree(tree[node].left) + count_subtree(tree[node].right);
}

void solve() {
	int curr = tar1;
	while (curr != 0) {
		visited[curr] = true;
		curr = tree[curr].parent;
	}

	int lca = tar2;
	while (lca != 0) {
		if (visited[lca]) break;
		lca = tree[lca].parent;
	}

	int size = count_subtree(lca);

	ans = make_pair(lca, size);
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		input();
		solve();
		cout << '#' << t << ' ' << ans.first << ' ' << ans.second << '\n';
	}
	return 0;
}