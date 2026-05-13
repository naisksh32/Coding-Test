#include <iostream>
#include <queue>
#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int arr[100001];
priority_queue<int, vector<int>, greater<int>> pq;
int del[10001];

int main() {
	cin >> N;
	int total = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];

		total += arr[i];
		pq.push(arr[i]);
	}

	double max_avg = 0;
	for (int i = 1; i <= N - 2; i++) {
		total -= arr[i];
		del[arr[i]]++;

		while (!pq.empty() && del[pq.top()] > 0) {
			del[pq.top()]--;
			pq.pop();
		}

		int tmp = total;
		double avg = (double)(tmp - pq.top()) / (N - i - 1);
		max_avg = max(max_avg, avg);
	}


	printf("%.2f", max_avg);

	return 0;
}