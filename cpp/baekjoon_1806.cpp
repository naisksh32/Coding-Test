#include <algorithm>
#include <iostream>
using namespace std;

int N, S;
int arr[100001];
int len = 21e8;

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int tmp_sum = arr[0];
    int ep = 0;

    for (int sp = 0; sp < N; sp++) {
        while (ep < N && tmp_sum < S) {
            ep++;
            if (ep != N)
                tmp_sum += arr[ep];
        }

        if (ep == N)
            break;
        len = min(len, ep - sp + 1);
        tmp_sum -= arr[sp];
    }

    if (len == 21e8)
        len = 0;

    cout << len;
    return 0;
}