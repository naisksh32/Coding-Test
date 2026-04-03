#include <iostream>
#include <algorithm>
using namespace std;


int N, K;
int weight[100001];

struct MM {
	int W, V;
};
MM mm[101];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int w, v;
		cin >> w >> v;
		mm[i] = { w, v };
	}

	for (int i = 0; i < N; i++) {
		
		for (int k = K; k >= mm[i].W; k--) {
			weight[k] = max(weight[k], (weight[k - mm[i].W] + mm[i].V));
		}

	}

	cout << weight[K];

	return 0;
}