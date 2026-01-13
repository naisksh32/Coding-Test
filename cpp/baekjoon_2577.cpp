#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;
    string s = to_string(A*B*C);
    
    for(int i=0; i<=9; i++){
        int cnt = 0;

        for(auto c: s){
            if(c==(i+'0')) cnt++;
        }

        cout << cnt << endl;
    }


    return 0;
}