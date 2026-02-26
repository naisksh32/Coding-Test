#include <iostream>
#include <algorithm>
using namespace std;

long long N;
long long arr[100001];
long long nnn = 0;

int main() {
	// 최댓값
	long long max_cost = 0;
	// 탐색할 인덱스 번호
	long long idx = 0;

	// 입력
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// 주어진 가격 배열을 내림차순으로 정렬
	sort(arr, arr + N, greater<long long>());


	// 각 요소들에 대해 비교 진행
	for (int i = 0; i < N; i++) {
		// 만약 지금 값이 기존 값이랑 같다면 pass
		if (i > 0 && arr[i - 1] == arr[i]) continue;

		long long cost = arr[i];
		long long ttt = 0;

		ttt += cost * (idx);

		for (int j = idx; j < N; j++) {
			if (arr[j] >= cost) {
				ttt += cost;
			}
			else {
				idx = j;
				break;
			}
		}

		if (ttt >= max_cost) {
			max_cost = ttt;
			nnn = cost;
		}
	}

	cout << max_cost << " " << nnn;

	return 0;
}
