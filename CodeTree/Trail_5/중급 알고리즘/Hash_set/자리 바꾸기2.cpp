#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int N, K;
int arr[100001];
pair<int, int> change[100001];

unordered_set<int> s[100001];

int ans[100001];

// 위치 바꾸기
void swap(int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		arr[i] = i;
		s[i].insert(i);
	}

	for (int k = 0; k < K; k++) {
		int a, b;
		cin >> a >> b;
		change[k] = make_pair(a, b);
	}

	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < K; k++) {
			int a = change[k].first;
			int b = change[k].second;

			swap(a, b);
			s[a].insert(arr[a]);
			s[b].insert(arr[b]);
		}
	}

	for (int i = 1; i <= N; i++) {
		//cout << i << ": ";
		unordered_set<int>::iterator it;
		for (it = s[i].begin(); it != s[i].end(); it++) {
			//cout << *it << ' ';
			ans[*it]++;
		}
		//cout << '\n';
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}