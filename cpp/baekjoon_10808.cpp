#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    
    vector<char> alphabet;
    for(char a='a'; a<='z'; a++){
        int cnt = 0;
        for(auto c: s){
            if(a==c){
                cnt++;
            }
        }
        cout << cnt << " ";
    }

    return 0;
}