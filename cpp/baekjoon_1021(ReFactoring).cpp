#include <iostream>
#include <deque>
using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    deque<int> dq;
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    int cnt = 0; // 총 연산 횟수

    for (int i = 0; i < m; i++) {
        int target_num;
        cin >> target_num;

        // 1. 타겟이 현재 덱의 몇 번째 인덱스에 있는지 찾기 (탐색)
        // 덱을 돌리지 않고 배열처럼 dq[j]로 바로 접근합니다.
        int index = 0;
        for (int j = 0; j < dq.size(); j++) {
            if (dq[j] == target_num) {
                index = j;
                break;
            }
        }

        // 2. 왼쪽으로 돌릴지, 오른쪽으로 돌릴지 결정
        // 왼쪽으로 이동하는 비용: index
        // 오른쪽으로 이동하는 비용: dq.size() - index
        if (index <= dq.size() / 2) {
            // 왼쪽으로 회전 (2번 연산)
            for (int j = 0; j < index; j++) {
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        } 
        else {
            // 오른쪽으로 회전 (3번 연산)
            // 오른쪽은 (전체 크기 - 인덱스) 만큼만 돌리면 됨
            for (int j = 0; j < dq.size() - index; j++) {
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }

        // 3. 맨 앞에 왔으니 삭제 (1번 연산)
        dq.pop_front();
    }

    cout << cnt << "\n";
    return 0;
}