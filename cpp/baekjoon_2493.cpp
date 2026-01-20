#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    // 탑의 갯수를 입력받
    int n;
    cin >> n;

    // 스택 자료형 형성
    stack<pair <int, int>> towers;
    // 답안을 저장할 배열
    vector<int> arr;

    
    // 주어진 탑의 갯수만큼 반복
    for(int i=0; i<n; i++){
        // 탑의 높이 입력받기
        int height;
        cin >> height;

        // 만약 타워 요소가 있으면서 더 큰 탑이 들어오면, 기존의 작은 요소들은 pop
        while(!towers.empty() && towers.top().second < height){
            towers.pop();
        }

        // 만약 타워가 비어있으면 0을 수신
        if (towers.empty()){
            arr.push_back(0);
        }
        // 만약 타워 안 요소가 있으면 그 번호를 수신
        else{
            arr.push_back(towers.top().first);
        }

        // {타워 번호, 높이} 쌍으로 스택에 저장
        towers.push({i+1, height});
    }

    // 답안 출력
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}