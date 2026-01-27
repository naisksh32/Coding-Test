#include <iostream>
using namespace std;


int DAT[20000001] = { 0 };

int main() {
	// 입출력 빠르게, 안하면 timeout남
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		n += 10000000;
		DAT[n]++;
	}


	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int m;
		cin >> m;
		m += 10000000;
		cout << DAT[m] << " ";
	}


	return 0;
}