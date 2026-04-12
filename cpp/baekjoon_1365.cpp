#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[100001];
vector<int> rope;


int binary_search(int element) {
	int left = 0, right = rope.size() - 1;
	int min_pos = rope.size();

	while (left <= right) {
		int mid = (left + right) / 2;
		if (rope[mid] > element) {
			right = mid - 1;
			min_pos = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return min_pos;
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	rope.push_back(arr[0]);


	for (int i = 1; i < N; i++) {
		if (rope.back() < arr[i]) {
			rope.push_back(arr[i]);
		}
		else {
			int idx = binary_search(arr[i]);
			rope[idx] = arr[i];
		}
	}

	cout << N - rope.size();
	return 0;
}