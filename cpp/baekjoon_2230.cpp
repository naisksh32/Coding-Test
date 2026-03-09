#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100001];

int main() {
	int ans = 21e8;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N, less<int>());

	int sp = 0;
	int ep = 0;
	int first, second;

	while (sp<N && ep<N) {
		first = arr[sp]; second = arr[ep];

		if (second - first < M) {
			ep++;
		}
		else {
			ans = min(ans, second - first);
			sp++;
		}
	}

	cout << ans;

	return 0;
}