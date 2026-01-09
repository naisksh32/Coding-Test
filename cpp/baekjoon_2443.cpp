#include <iostream>
using namespace std;


int main(){
    int N;
    cin >> N;
    for(int n=1; n<(N+1); n++){
        for(int space=0; space<(n-1); space++){
            cout << " ";
        }

        for(int star=(N-n)*2+1; star>0; star--){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}