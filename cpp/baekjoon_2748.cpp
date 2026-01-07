#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    // n+1 크기의 배열 생성 (0번째 인덱스부터 쓰기 위해)
    vector<long long> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;

    // 작은 수부터 차근차근 쌓아 올림
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n] << endl;
    
    return 0;
}