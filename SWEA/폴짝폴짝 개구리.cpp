#include <iostream>
using namespace std;


struct POS {
	int x1, x2, y;
};
POS poses[100001];
bool is_group[100001] = { false };

// Union-Find
int parent[100001];
int Find(int now) {
	if (now == parent[now]) return now;
	return parent[now] = Find(parent[now]);
}
void Union(int A, int B) {
	int rootA = Find(A);
	int rootB = Find(B);
	if (rootA == rootB) return;
	parent[rootB] = rootA;
}


int main() {
	// 입력
	int N, Q;
	cin >> N >> Q;

	for (int n = 1; n <= N; n++) {
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		poses[n] = { x1, x2, y };

		parent[n] = n;
	}

	// 그룹 추가
	for (int p = 1; p <= N; p++) {
		if (is_group[p] == true) continue;

		int left_x = poses[p].x1, right_x = poses[p].x2;
		is_group[p] = true;
		for (int i = 2; i <= N; i++) {
			if (right_x >= poses[i].x1) {
				Union(1, i);
				is_group[i] = true;
				right_x = poses[i].x2;
			}
		}
	}
	

	//cout << left_x << " " << right_x << endl;

	// 판단: Find를 활용해서 부모 노드가 같은지 확인
	for (int q = 0; q < Q; q++) {
		int start, end;
		cin >> start >> end;

		if (Find(start) == Find(end)) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}

	return 0;
}
