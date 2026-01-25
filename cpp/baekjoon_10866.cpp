#include <iostream>
#include <string>
using namespace std;

int main() {
    // 입출력 속도 향상 (백준 필수)
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int deque[20001]; // 넉넉한 크기
    
    int p;
    cin >> p;

    // 시작점을 중간으로 설정
    int head = 10000;
    int tail = 10000;
    
    for(int i=0; i<p; i++){
        string cmd;
        cin >> cmd;

        // switch -> if-else if 로 변경
        if (cmd == "push_front") {
            int n;
            cin >> n;
            deque[--head] = n; // 앞으로 이동 후 저장
        }
        else if (cmd == "push_back") {
            int n;
            cin >> n;
            deque[tail++] = n; // 저장 후 뒤로 이동
        }
        else if (cmd == "pop_front") {
            if(head == tail){
                cout << -1 << "\n";
            } else {
                cout << deque[head++] << "\n";
            }
        }
        else if (cmd == "pop_back") {
            if(head == tail){
                cout << -1 << "\n";
            } else {
                cout << deque[--tail] << "\n";
            }
        }
        else if (cmd == "size") {
            cout << tail - head << "\n";
        }
        else if (cmd == "empty") {
            // head와 tail이 같으면 비어있음 (1), 아니면 0
            cout << (head == tail ? 1 : 0) << "\n";
        }
        else if (cmd == "front") {
            if(head == tail){
                cout << -1 << "\n";
            } else {
                cout << deque[head] << "\n";
            }
        }
        else if (cmd == "back") {
            if(head == tail){
                cout << -1 << "\n";
            } else {
                // [중요 수정] tail은 빈 공간이므로 tail-1을 출력해야 함
                cout << deque[tail - 1] << "\n"; 
            }
        }
    }
    
    return 0;
}