#include <iostream>
using namespace std;


int main(){
    int N, answer=0;
    cin >> N;

    for(int i=0; i<(N+1); i++){
        for(int j=i; j<(N+1); j++){
            answer += i+j;
        }
    }
    cout << answer << endl;
    return 0;
}