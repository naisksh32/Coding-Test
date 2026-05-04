#include <iostream>
#include <set>
using namespace std;

int N;
set<int> s;

int main() {
	s.insert(0);
	int min_dist = 21e8;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		s.insert(n);

		set<int>::iterator it;
		it = s.find(n);
		
		it++;
		if (it != s.end()) {
			min_dist = min(min_dist, *it - n);
		}

		it = s.find(n);
		if (it-- != s.begin()) {
			min_dist = min(min_dist, n - *it);
		}

		cout << min_dist << '\n';
	}

	return 0;
}