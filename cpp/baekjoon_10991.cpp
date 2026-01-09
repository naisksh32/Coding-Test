#include <iostream>
using namespace std;


int main(){
    int N;
    cin >> N;

    for(int n=1; n<(N+1); n++){
        for(int space=(N-n); space>0; space--){
            cout << " ";
        }
        for(int p=0; p<n; p++){
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}