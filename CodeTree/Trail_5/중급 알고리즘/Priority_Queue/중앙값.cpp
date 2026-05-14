#include <iostream>
#include <queue>
using namespace std;


int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		priority_queue<int, vector<int>, greater<int>> upper;	// 오름차순
		priority_queue<int, vector<int>, less<int>> lower;		// 내림차순

		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;

			// 초기 값 대입
			if (upper.empty()) {
				upper.push(n);
			}
			else {
				// upper의 하위값이랑 비교해 작으면 lower에 넣고, 크면 upper에 넣기
				if (n < upper.top()) lower.push(n);
				else upper.push(n);
			}

			// load valancing - 균형 맞추기
			if (lower.size() > upper.size()) {
				int lowtop = lower.top();	lower.pop();
				upper.push(lowtop);
			}
			else if (upper.size() - lower.size() >= 2) {
				int uptop = upper.top();	upper.pop();
				lower.push(uptop);
			}

			// 홀수번째 투입마다 중앙값 출력
			if (i % 2 == 0) cout << upper.top() << ' ';
		}

		cout << '\n';
	}

	return 0;
}