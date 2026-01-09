#include <iostream>
using namespace std;


int main(){
    int N, answer=0;
    cin >> N;

    for(int n=0; n<N; n++){
        int plug;
        cin >> plug;
        
        answer += plug;
        answer--;
    }

    cout << answer+1 << endl;

    return 0;
}