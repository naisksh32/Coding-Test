#include <iostream>
using namespace std;


int main(){
    int N;
    cin >> N;

    for(int n=1; n<(2*N); n++){
        if(n<=N){
            for(int space=1; space<n; space++){
                cout << " ";
            }
            for(int star=(2*(N-n)+1); star>0; star--){
                cout << "*";
            }
        }else{
            for(int space=(2*N-n-1); space>0; space--){
                cout << " ";
            }
            for(int star=0; star<2*(n-N)+1; star++){
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}