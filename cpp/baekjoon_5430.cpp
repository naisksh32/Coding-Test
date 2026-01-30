#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    for(int t=0; t<T; t++){
        
        // input 로직
        string cmd, q_arr;
        int n;
        cin >> cmd >> n >> q_arr;

        deque<int> dq;

        if(n>0){
            string a = q_arr.substr(1, q_arr.length() - 2);
            // 정상적 파싱 진행
            a += ',';
            int f_idx = -1;    // 찾는 인덱스
            int s_idx = -1;    // 기존 위치 인덱스
    
            while(true){
                f_idx = a.find(',', f_idx+1);
                if(f_idx == -1) break;
                
                int len = f_idx - s_idx - 1;
                int num = stoi(a.substr(f_idx - len, len));
    
                dq.push_back(num);
                
                s_idx = f_idx;
                f_idx += 1;
            }
        }

        

        // cmd 조정
        // 만약 RR이라는 커맨드는 뒤집고 다시 뒤집으므로 소용이 없음
        int aa = 0;
        int bb = 0;
        while(true){
            bb = cmd.find("RR", aa);
            if(bb==-1) break;
            cmd.erase(bb, 2);
            
            aa = bb+1;
        }
        // cout << cmd << endl;
        
        
        // Deque 로직
        bool kg = true;
        bool is_r = false;
        
        for(char c: cmd){

            if(c == 'R'){
                is_r = (is_r) ? false : true;
            }
                
            else if(c=='D'){
                if(dq.empty()){
                    cout << "error" << endl;
                    kg = false;
                    break;
                }
                (is_r) ? dq.pop_back() : dq.pop_front();
            }
        }

        if(is_r){
            reverse(dq.begin(), dq.end());
        }
        
        // 출력
        if(kg){
            cout << '[';
            for(int i=0; i<dq.size(); i++){
                cout << dq[i];
                
                if(i != dq.size()-1){
                    cout << ',';
                }
                
            }
            cout << ']' << endl;
        }
        
    }

    
    return 0;
}