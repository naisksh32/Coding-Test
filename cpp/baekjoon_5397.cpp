#include <iostream>
#include <list> // vector 대신 list 사용
#include <string>

using namespace std;

void func(){
    string s;
    cin >> s;
    
    list<char> sentence;
    // 커서(반복자)는 리스트의 시작과 끝 사이를 가리킵니다.
    // 초기값은 문장이 비어있으므로 end()입니다.
    auto cursor = sentence.begin(); 

    for(auto c : s){
        if(c == '<'){
            // 커서가 맨 앞이 아니면 왼쪽으로 이동
            if(cursor != sentence.begin()){
                cursor--;
            }
        }
        else if(c == '>'){
            // 커서가 맨 뒤가 아니면 오른쪽으로 이동
            if(cursor != sentence.end()){
                cursor++;
            }
        }
        else if(c == '-'){
            // 커서가 맨 앞이 아니면, 커서 '앞'의 글자를 삭제
            if(cursor != sentence.begin()){
                // 삭제 후 cursor가 유효하려면, 
                // cursor 앞을 가리키는 임시 반복자를 만들어 삭제해야 함
                auto temp = cursor;
                temp--; 
                sentence.erase(temp);
            }
        }
        else {
            // 일반 문자는 커서 위치에 삽입
            // list::insert는 해당 iterator '앞'에 삽입하고,
            // cursor 위치는 변하지 않음 (새로 들어온 글자 뒤에 위치하게 됨)
            sentence.insert(cursor, c);
        }
    }

    // 출력
    for(auto c : sentence){
        cout << c;
    }
}

int main() {
    // 입출력 속도 향상 (알고리즘 문제 필수)
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        func();
        cout << "\n"; // endl보다 \n이 빠름
    }
    
    return 0;
}