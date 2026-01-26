#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    int n, m;
    cin >> n >> m;

    // 1~n까지 deque에 집어 넣기
    for(int i=1; i<=n; i++){
        dq.push_back(i);
    }

    
    int cnt=0;    // 연산 횟수 세기
    int pre_target = n/2;
    
    // 주어진 특정 수를 뽑아내기
    for(int i=0; i<m; i++){
        // 목표로 하는 수 target_num 설정
        int target_num;
        cin >> target_num;

        // target_num이 deque에서 몇번째 인덱스에 있는지 한개씩 요소를 살펴 봄.
        int from_front;
        for(int i=0; i<dq.size(); i++){
            if(target_num==dq.front()){
                from_front = i;
            }

            int temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);
        }
        // 뒤에서 몇번째는 전체 사이즈에서 앞의 길이만큼 빼기.
        int from_back = dq.size()-from_front;

        
        // dq의 맨 앞의 요소와 target_num이랑 같지 않을 경우
        // 2번 3번 연산을 진행
        while(dq.front() != target_num){
            // 2번 연산 수행 (뒷쪽으로 빼는게 효율적)
            if(from_front < from_back){
                int temp = dq.front();
                dq.pop_front();
                dq.push_back(temp);
            }
            // 3번 연산을 수행 (앞쪽으로 빼는게 효율)
            else {
                int temp = dq.back();
                dq.pop_back();
                dq.push_front(temp);
            }
            
            // 연산 횟수 1 증가
            cnt++;
        }
        // dq의 맨 앞의 요소와 target_num이 동일하면
        // 1번 연산 진행
        dq.pop_front();
        pre_target = target_num;
    }
    
    cout << cnt;
    return 0;
}