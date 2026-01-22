#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    stack<char> st;
    long long result = 0; // 최종 점수 합산
    long long tmp = 1;    // 현재 괄호 깊이의 곱셈 값 (임시 변수)

    for (int i = 0; i < s.length(); i++) {
        // 1. 여는 괄호: 곱하기
        if (s[i] == '(') {
            tmp *= 2;
            st.push('(');
        } 
        else if (s[i] == '[') {
            tmp *= 3;
            st.push('[');
        } 
        // 2. 닫는 괄호: 나누기 & 정답 더하기
        else if (s[i] == ')') {
            // 빈 스택이거나 짝이 안 맞으면 -> 잘못된 문자열
            if (st.empty() || st.top() != '(') {
                cout << 0 << "\n";
                return 0;
            }
            // 바로 직전 문자가 '(' 였다면 -> 가장 깊은 곳임 -> 정답에 더하기
            if (s[i-1] == '(') {
                result += tmp;
            }
            st.pop();
            tmp /= 2; // 괄호 밖으로 나옴
        } 
        else if (s[i] == ']') {
            // 빈 스택이거나 짝이 안 맞으면
            if (st.empty() || st.top() != '[') {
                cout << 0 << "\n";
                return 0;
            }
            // 바로 직전 문자가 '[' 였다면 -> 정답에 더하기
            if (s[i-1] == '[') {
                result += tmp;
            }
            st.pop();
            tmp /= 3; // 괄호 밖으로 나옴
        }
    }

    // 모든 과정이 끝났는데 스택에 남은 게 있다면 올바르지 않은 괄호
    if (!st.empty()) {
        cout << 0 << "\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}