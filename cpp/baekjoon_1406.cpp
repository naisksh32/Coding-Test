#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string initial_str;
    cin >> initial_str;

    // 1. string을 list에 옮겨 담기
    list<char> sentence;
    for(char c : initial_str){
        sentence.push_back(c);
    }

    // 커서는 문장의 맨 뒤에서 시작
    auto cursor = sentence.end();

    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        char C;
        cin >> C;

        if(C == 'P'){
            char p;
            cin >> p;
            // insert는 삽입 후, 커서 위치는 그대로(새로 추가된 문자 뒤) 유지됨
            sentence.insert(cursor, p);
        } 
        else if (C == 'L'){
            if(cursor != sentence.begin()){
                cursor--;
            }
        } 
        else if (C == 'D'){ // 2. 'B' -> 'D'로 수정
            if(cursor != sentence.end()){
                cursor++;
            }
        } 
        else if (C == 'B'){
            // 4. 맨 앞이 아닐 때만 삭제
            if(cursor != sentence.begin()){
                cursor--; 
                // 3. 삭제 후 반환값을 다시 cursor에 저장 (매우 중요!)
                cursor = sentence.erase(cursor);
            }
        }
    }

    // 1. 출력은 반복문으로
    for(auto c : sentence){
        cout << c;
    }
    cout << "\n";

    return 0;
}