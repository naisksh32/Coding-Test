#include <iostream>
#include <string>
#include <vector>
#include <cmath> // abs 함수(절댓값) 사용을 위해 필요

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    // 알파벳 빈도수를 저장할 배열 (a~z: 26개)
    vector<int> count1(26, 0);
    vector<int> count2(26, 0);

    // 첫 번째 문자열의 알파벳 개수 세기
    // 이전 코드처럼 인덱스 공유 문제를 막기 위해 각각 따로 반복문을 돌립니다.
    for(int i = 0; i < s1.size(); i++) {
        count1[s1[i] - 'a']++;
    }

    // 두 번째 문자열의 알파벳 개수 세기
    for(int i = 0; i < s2.size(); i++) {
        count2[s2[i] - 'a']++;
    }

    int result = 0;

    // a부터 z까지 순회하며 차이 계산
    for(int i = 0; i < 26; i++) {
        // 두 배열 값의 차이(절댓값)만큼 제거해야 함
        // abs() 함수는 절대값을 반환합니다. (예: abs(2-5) = 3)
        result += abs(count1[i] - count2[i]);
    }

    cout << result << endl;

    return 0;
}