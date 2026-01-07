#include <iostream>
#include <string>
// vector, algorithm 헤더 불필요

using namespace std;

void solve() {
    int p;
    cin >> p;

    // 최댓값을 기록할 변수 (초기화 중요!)
    int max_cost = -1; 
    string max_name = "";

    for(int i = 0; i < p; i++) {
        int cost;
        string name;
        cin >> cost >> name;

        // [핵심] 입력받은 즉시 비교하고, 필요 없으면 버림 (저장 X)
        if (cost > max_cost) {
            max_cost = cost;
            max_name = name;
        }
    }

    cout << max_name << endl;
}

int main() {
    // 1. 입출력 속도 향상 (필수)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {
        solve();
    }

    return 0;
}