#include <iostream>
using namespace std;

int main(){
    int M, N;
    cin >> M >> N;

    int sum = 0;
    int min_prime = -1;

    for(int i=M; i<=N; i++){
        bool is_prime = true;

        if(i<2){
            is_prime = false;
        } else {
            for(int j=2; j*j<=i; j++){
                if(i%j==0){
                    is_prime = false;
                    break;
                }
            }
        }

        if(is_prime){
            sum += i;

            if(min_prime == -1){
                min_prime = i;
            }
        }
    }

    if(min_prime == -1){
        cout << -1 << endl;
    } else {
        cout << sum << endl;
        cout << min_prime << endl;
    }

    return 0;
}