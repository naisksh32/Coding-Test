#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long a, b; 
    cin >> a >> b;
    
    if (a == b) {
        cout << 0 << endl;
        return 0;
    }

    long long c, d;
    if (a > b){
        c = b;
        d = a;
    } else {
        c = a;
        d = b;
    }

    cout << d - c - 1 << endl;

    for(long long i = c + 1; i < d; i++){
        cout << i << " ";
    }

    return 0;
}