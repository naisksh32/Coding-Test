#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int N, M;
set<int> s;

int main() {
	cin >> N >> M;
	
	int mm_dist = 21e8;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		auto it_left = s.upper_bound(n - M);
		if (it_left != s.begin()) {
			it_left--;
			mm_dist = min(mm_dist, n - (*it_left));
		}

		auto it_right = s.lower_bound(n + M);
		if (it_right != s.end()) {
			mm_dist = min(mm_dist, (*it_right) - n);
		}

		s.insert(n);
	}

	(mm_dist != 21e8) ? cout << mm_dist : cout << -1;

	return 0;
}