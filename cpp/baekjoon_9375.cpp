#include <iostream>
#include <unordered_map>
using namespace std;


int T, N;


int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		unordered_map<string, int> m;

		cin >> N;
		for (int i = 0; i < N; i++) {	
			string name, type;
			cin >> name >> type;

			m[type]++;
		}
		int ans = 1;

		for (auto p : m) {
			ans *= (p.second + 1);
		}

		cout << ans - 1 << '\n';
	}

	return 0;
}