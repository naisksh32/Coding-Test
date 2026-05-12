#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int> pq;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		pq.push(n);
	}

	while (pq.size() > 1) {
		int first = pq.top();	pq.pop();
		int second = pq.top();	pq.pop();

		if (first == second) continue;
		pq.push(first - second);
	}

	(!pq.empty()) ? cout << pq.top() : cout << -1;

	return 0;
}