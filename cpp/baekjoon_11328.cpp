#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    // 만약 문제 입력에 테스트 케이스 개수(N)가 없다면 
    // cin >> n; 과 for문은 제거해야 합니다.
    if (cin >> n) { 
        for(int i=0; i<n; i++){
            string before, after;
            cin >> before >> after;

            // [수정된 부분] 길이 체크를 가장 먼저 수행
            if (before.size() != after.size()) {
                cout << "Impossible" << endl;
                continue; // 다음 테스트 케이스로 넘어감
            }

            vector<int> b(26);
            vector<int> a(26);

            // 이제 길이가 같음이 보장되므로 안전하게 반복 가능
            for(int p=0; p<before.size(); p++){
                b[before[p] - 'a']++;
                a[after[p] - 'a']++;
            }

            bool flag = true;
            for(int k=0; k<26; k++){
                if(b[k] != a[k]){
                    flag = false;
                    break;
                }
            }
            
            if(flag) cout << "Possible" << endl;
            else cout << "Impossible" << endl;
        }
    }
    return 0;
}