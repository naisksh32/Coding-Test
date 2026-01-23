#include <iostream>
#include <string>
using namespace std;

// 명령의 최대 개수만큼 배열 크기 확보 (넉넉하게)
// 전역 변수로 선언하면 자동으로 0 초기화되고 메모리 스택 오버플로우 방지
int queue[10005]; 
int begin_idx = 0; // 큐의 맨 앞 (삭제될 위치)
int end_idx = 0;   // 큐의 맨 뒤 (추가될 위치)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int num;
            cin >> num;
            // 1. end 위치에 값을 넣고
            // 2. end를 한 칸 뒤로 이동
            queue[end_idx] = num;
            end_idx++;
        } 
        else if (cmd == "pop") {
            // 비어있는지 확인: begin과 end가 같으면 데이터가 없는 것
            if(begin_idx == end_idx) {
                cout << -1 << "\n";
            } else {
                // 맨 앞의 값을 출력하고
                cout << queue[begin_idx] << "\n";
                // begin을 한 칸 뒤로 이동 (마치 삭제된 것처럼 취급)
                begin_idx++;
            }
        } 
        else if (cmd == "size") {
            // 들어간 갯수(end) - 나간 갯수(begin)
            cout << end_idx - begin_idx << "\n";
        } 
        else if (cmd == "empty") {
            // 두 커서가 같은 위치면 텅 빈 상태
            cout << (begin_idx == end_idx ? 1 : 0) << "\n";
        } 
        else if (cmd == "front") {
            if(begin_idx == end_idx) {
                cout << -1 << "\n";
            } else {
                cout << queue[begin_idx] << "\n";
            }
        } 
        else if (cmd == "back") {
            if(begin_idx == end_idx) {
                cout << -1 << "\n";
            } else {
                // 주의: end는 '빈 공간'을 가리키므로, 
                // 실제 마지막 데이터는 end - 1 위치에 있음
                cout << queue[end_idx - 1] << "\n";
            }
        }
    }
    return 0;
}