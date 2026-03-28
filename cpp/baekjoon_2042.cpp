#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
long long arr[1000001];
long long tree[4000004];

// 트리 생성 함수
long long init(int node, int start, int end) {

	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;
	long long left_sum = init(node * 2, start, mid);
	long long right_sum = init(node * 2 + 1, mid + 1, end);

	return tree[node] = left_sum + right_sum;
}


// 업데이트
void update(int node, int start, int end, int target_idx, long long diff) {

	if (start > target_idx || target_idx > end) return;

	tree[node] += diff;

	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, target_idx, diff);
		update(node * 2 + 1, mid + 1, end, target_idx, diff);
	}
}


// 합 구하기
long long query(int node, int start, int end, int left, int right) {

	if (right < start || end < left) return 0;

	if (left <= start && end <= right) return tree[node];


	int mid = (start + end) / 2;
	long long left_sum = query(node * 2, start, mid, left, right);
	long long right_sum = query(node * 2 + 1, mid + 1, end, left, right);

	return left_sum + right_sum;
}



int main() {
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	// 세그먼트 트리 생성
	init(1, 1, N);

	for (int i = 0; i < M + K; i++) {
		long long a, b, c;
		cin >> a >> b >> c;

		// 수 변경
		if (a == 1) {
			long long diff = c - arr[b];
			update(1, 1, N, b, diff);
			arr[b] = c;
		}
		// 범위 합
		else if (a == 2) {
			long long ans = query(1, 1, N, b, c);
			cout << ans << '\n';
		}
	}

	return 0;
}