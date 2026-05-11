#include <iostream>
#include <set>
using namespace std;

int N, M;
set<int> s;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}

	for (int i = 0; i < M; i++) {
		int query;
		cin >> query;

		auto it = s.upper_bound(query);

		if (it == s.begin()) {
			cout << -1 << '\n';
		}
		else {
			it--;
			cout << *it << '\n';
			s.erase(it);
		}
	}

	return 0;
}