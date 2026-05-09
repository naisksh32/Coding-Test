#include <iostream>
#include <set>
using namespace std;

int N, M;
int P, L;
string cmd;
int x;

set<int> level[101];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P >> L;
		level[L].insert(P);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> cmd;

		if (cmd == "ad") {
			cin >> P >> L;
			level[L].insert(P);
		}
		else if (cmd == "sv") {
			cin >> P >> L;
			level[L].erase(P);
		}
		else if (cmd == "rc") {
			cin >> x;
			if (x == 1) {
				for (int i = 100; i > 0; i--) {
					if (level[i].empty()) continue;

					auto it = level[i].end();
					cout << *(--it) << '\n';
					break;
				}
			}
			else if (x == -1) {
				for (int i = 1; i <= 100; i++) {
					if (level[i].empty()) continue;

					auto it = level[i].begin();
					cout << *it << '\n';
					break;
				}
			}
		}
	}
	return 0;
}