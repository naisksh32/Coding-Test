#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> arr;
    // 문제의 수 범위에 따라 크기 조절 필요 (보통 100000 ~ 2000000)
    // 넉넉하게 200만으로 잡거나, 문제의 Ai 최대값 확인 필요
    vector<int> nums(2000001, 0); 

    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
        nums[num] = 1; // [수정 1] 입력받은 숫자 위치에 표시
    }

    int x;
    cin >> x;

    int cnt = 0;
    for(int j=0; j<arr.size(); j++){
        int target = x - arr[j];
        
        // [수정 2] 인덱스 범위 체크 (음수이거나 너무 크면 패스)
        if (target < 0 || target >= 2000001) continue;

        if(nums[target]) {
            cnt++;
        }
    }

    // [수정 3] 중복 제거 (쌍이니까 2로 나누기)
    cout << cnt / 2;

    return 0;
}