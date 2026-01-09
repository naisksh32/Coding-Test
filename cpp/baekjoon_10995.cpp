#include <iostream>
using namespace std;


int main(){
    int N;
    cin >> N;

    for(int n=1; n<(N+1); n++){
        if(n%2==1){
            for(int p=0; p<N; p++){
                cout << "* ";
            }
        }else{
            for(int p=0; p<N; p++){
                cout << " *";
            }
        }
        cout << endl;
    }

    return 0;
}