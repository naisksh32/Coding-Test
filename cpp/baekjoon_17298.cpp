#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &num: arr){
        cin >> num;
    }

    stack<int> s;
    vector<int> ans;
    
    // 뒤에서부터 탐색 (오른쪽 -> 왼쪽)
    for(int i = n - 1; i >= 0; i--){
        
        // 1. 스택에 나보다 작거나 같은 애들이 있으면 다 제거한다.
        // 이유: 내가(arr[i]) 걔네보다 크고 더 왼쪽에 있으니, 
        //       앞으로 만날 왼쪽 숫자들은 굳이 작은 걔네를 볼 필요가 없음.
        while(!s.empty() && s.top() <= arr[i]){
            s.pop();
        }
        
        // 2. 스택이 비었으면 오큰수 없음(-1), 있으면 top이 오큰수
        if(s.empty()) {
            ans.push_back(-1);
        } else {
            ans.push_back(s.top());
        }
        
        // 3. 현재 숫자를 스택에 후보로 등록
        s.push(arr[i]);
    }

    // 뒤에서부터 구했으므로 순서가 거꾸로 되어있음 -> 다시 뒤집기
    reverse(ans.begin(), ans.end());
    
    for(int i: ans){
        cout << i << " ";
    }
    
    return 0;
}