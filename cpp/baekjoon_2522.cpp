#include <iostream>
using namespace std;


int main(){
    int N;
    cin >> N;

    for(int n=1; n<(N+1); n++){
        for(int space=(N-n); space>0; space--){
            cout << " ";
        }
        for(int star=0; star<n; star++){
            cout << "*";
        }
        cout << endl;
    }

    for(int n=(N-1); n>0; n--){
        for(int space=0; space<(N-n); space++){
            cout << " ";
        }
        for(int star=n; star>0; star--){
            cout << "*";
        }
        cout << endl;
    }


    return 0;
}