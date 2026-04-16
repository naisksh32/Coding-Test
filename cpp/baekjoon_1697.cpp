#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[100001];
bool visited[100001];

int main() {

	int N, K;
	cin >> N >> K;

	arr[N] = 1;

	queue<int> q;
	q.push(N);
	visited[N] = true;

	while (!q.empty()) {
		int now = q.front(); q.pop();

		if (now == K) {
			cout << arr[K] - 1;
			break;
		}

		int d1 = now + 1;
		if (d1 < 100001 && arr[d1] == 0) {
			arr[d1] = arr[now] + 1;
			q.push(d1);
		}
		
		int d2 = now - 1;
		if (d2 >= 0 && arr[d2] == 0) {
			arr[d2] = arr[now] + 1;
			q.push(d2);
		}

		int d3 = now * 2;
		if (d3 < 100001 && arr[d3] == 0) {
			arr[d3] = arr[now] + 1;
			q.push(d3);
		}
	}

	return 0;
}
