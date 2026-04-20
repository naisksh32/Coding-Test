#include <iostream>
#include <map>
using namespace std;

map<int, int> m;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "add") {
			int k, v;
			cin >> k >> v;
			m[k] = v;
		}
		else if (cmd == "find") {
			int k;
			cin >> k;
			(m.find(k) != m.end()) ? cout << m[k] << '\n' : cout << "None" << '\n';
		}
		else if (cmd == "print_list") {
			if (m.empty()) {
				cout << "None\n";
				continue;
			}
			map<int, int> ::iterator it;
			for (it = m.begin(); it != m.end(); it++) {
				cout << it->second << ' ';
			}
			cout << '\n';
		}
		else if (cmd == "remove") {
			int k;
			cin >> k;
			m.erase(k);
		}

	}


	return 0;
}