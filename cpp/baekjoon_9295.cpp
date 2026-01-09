#include <iostream>
#include <cstdio>
using namespace std;


int main(){
    int T;
    cin >> T;
    
    for(int t=0; t<T; t++){
        int a, b;
        cin >> a >> b;
        printf("Case %d: %d\n", (t+1), a+b);
    }
    return 0;
}