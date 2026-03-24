#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

long long n;
long long cL, cR;

int min_cnt, max_cnt = 0;
bool is_check = false;

void BS(long long sp, long long ep, int cnt) {

    if (sp > ep)
        return;

    long long left = sp;
    long long right = ep;

    long long mid = (left + right) / 2;

    if (cL <= mid && mid <= cR) {
        if (!is_check) {
            min_cnt = cnt + 1;
            is_check = true;
        }
        max_cnt = max(max_cnt, cnt + 1);
    }

    if (cR < mid) {
        BS(left, mid - 1, cnt + 1);
    } else if (mid < cL) {
        BS(mid + 1, right, cnt + 1);
    } else {
        BS(left, mid - 1, cnt + 1);
        BS(mid + 1, right, cnt + 1);
    }
}

int main() {

    // 입력
    cin >> n;
    cin >> cL >> cR;

    // 좌우 범위 설정
    long long L = 1;
    long long R = n;

    BS(L, R, 0);

    cout << min_cnt << ' ' << max_cnt;

    return 0;
}
