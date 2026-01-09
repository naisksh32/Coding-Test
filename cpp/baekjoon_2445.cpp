#include <iostream>
using namespace std;


int main(){
    int N;
    cin >> N;

    for(int n=1; n<(2*N); n++){
        if(n<=N){
            for(int star=0; star<n; star++){
                cout << "*";
            }
            for(int space=(N-n)*2; space>0; space--){
                cout << " ";
            }
            for(int star=0; star<n; star++){
                cout << "*";
            }
        }else{
            for(int star=(2*N-n); star>0; star--){
                cout << "*";
            }
            for(int space=0; space<2*(n-N); space++){
                cout << " ";
            }
            for(int star=(2*N-n); star>0; star--){
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}