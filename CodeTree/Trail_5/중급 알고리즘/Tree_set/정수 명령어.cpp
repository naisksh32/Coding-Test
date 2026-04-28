#include <iostream>
#include <set>
using namespace std;


set<int> s;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int ccc;
		cin >> ccc;

		s.clear();
		for (int c = 0; c < ccc; c++) {
			char cmd;
			int n;
			cin >> cmd >> n;

			if (cmd == 'I') {
				s.insert(n);
			}
			else if (cmd == 'D') {
				if (s.empty()) continue;

				if (n == 1) {
					int max_n = *s.rbegin();
					s.erase(max_n);
				}
				else {
					int min_n = *s.begin();
					s.erase(min_n);
				}
			}
		}

		if (s.empty()) cout << "EMPTY\n";
		else {
			int ma_n = *s.rbegin();
			int mi_n = *s.begin();
			cout << ma_n << ' ' << mi_n << '\n';
		}
	}

	return 0;
}