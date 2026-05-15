#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> ppp;
priority_queue<int> mmm;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		if (n > 0) {
			ppp.push(n);
		}
		else if (n < 0) {
			mmm.push(n);
		}
		else if (n == 0) {
			if (ppp.empty() && mmm.empty()) cout << 0 << '\n';
			else if (ppp.empty()) {
				cout << mmm.top() << '\n';
				mmm.pop();
			}
			else if (mmm.empty()) {
				cout << ppp.top() << '\n';
				ppp.pop();
			}
			else {
				int a = ppp.top();
				int b = -(mmm.top());

				if (a < b) {
					cout << a << '\n';
					ppp.pop();
				}
				else {
					cout << -b << '\n';
					mmm.pop();
				}
			}
		}
	}
	return 0;
}