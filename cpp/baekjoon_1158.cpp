#include <iostream>
#include <list>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    // [수정] (N)을 제거하여 빈 리스트로 시작
    list<int> people; 
    
    for(int i=0; i<N; i++){
        people.push_back(i+1);
    }
    // 이제 리스트는 [1, 2, 3, ..., N] 상태가 됩니다.

    // 요세푸스 문제(백준 1158번 등)의 일반적인 출력 형식을 맞추기 위한 부분
    cout << "<";

    int cnt = 1;
    while (!people.empty()){
        if(cnt % K == 0){
            cout << people.front();
            people.pop_front();
            
            // 마지막 원소가 아니면 콤마 출력
            if (!people.empty()) {
                cout << ", ";
            }
        } else {
            people.push_back(people.front());
            people.pop_front();
        }
        cnt++;
    }
    
    cout << ">" << endl;
    
    return 0;
}