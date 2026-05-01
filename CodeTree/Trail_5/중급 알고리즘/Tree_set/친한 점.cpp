#include <iostream>
#include <set>
using namespace std;

int N, M;
set<pair<int, int>> s;


int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;

		s.insert({ a, b });
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		pair<int, int> near = (s.lower_bound({ a, b }) != s.end()) ? *s.lower_bound({ a, b }) : make_pair(-1, -1);
		cout << near.first << ' ' << near.second << '\n';
	}

	return 0;
}