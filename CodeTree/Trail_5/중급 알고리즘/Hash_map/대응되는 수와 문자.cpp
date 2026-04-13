#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int N, M;
unordered_map<string, int> m;
vector<string> v;


int main() {
	cin >> N >> M;
	v.push_back("null");
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;

		m[s] = i;
		v.push_back(s);
	}

	for (int i = 0; i < M; i++) {
		string cmd;
		cin >> cmd;

		try {
			int num = stoi(cmd);
			cout << v[num] << '\n';
		}
		catch (invalid_argument& e){
			cout << m[cmd] << '\n';
		}
	}

	return 0;
}