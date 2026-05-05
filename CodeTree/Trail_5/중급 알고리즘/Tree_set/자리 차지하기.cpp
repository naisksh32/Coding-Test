#include <iostream>
#include <set>
using namespace std;

int N, M;
set<int> s;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		s.insert(i);
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		auto it = s.upper_bound(n);
		if (it == s.begin()){
			break;
		}

		it--;
		s.erase(it);
		cnt++;
	}

	cout << cnt;
	return 0;
}