#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Element {
	int num;
	int idx;
};
deque<Element> dq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N >> L;


	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;

		// 맨 앞에 있는 값이 윈도우 범위를 벗어나면 pop
		if (!dq.empty() && dq.front().idx <= i - L) {
			dq.pop_front();
		}

		// 맨 뒤에 있는 값이 지금 들어오는 값보다 크면 pop
		while (!dq.empty() && dq.back().num >= n) {
			dq.pop_back();
		}

		// 요소를 dq에 push
		dq.push_back({ n, i });

		// 제일 작은 요소를 출력
		cout << dq.front().num << " ";

	}

	return 0;
}