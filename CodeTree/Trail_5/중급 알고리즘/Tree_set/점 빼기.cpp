#include <iostream>
#include <set>
#include <map>
using namespace std;

map<int, set<int>> pos;
int N, M;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		pos[x].insert(y);
	}

	for (int i = 0; i < M; i++) {
		int k;
		cin >> k;

		auto it = pos.lower_bound(k);

		if (it == pos.end()) {
			cout << -1 << ' ' << -1 << '\n';
			continue;
		}
		
		auto& y_set = it->second;

		cout << it->first << ' ' << *y_set.begin() << '\n';
		y_set.erase(y_set.begin());

		if ((it->second).size() == 0) {
			pos.erase(it);
		}
	}

	return 0;
}