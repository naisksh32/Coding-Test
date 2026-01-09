#include <iostream>
#include <cstdio>
using namespace std;


int main(){
    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        int c, v;
        cin >> c >> v;

        printf("You get %d piece(s) and your dad gets %d piece(s).\n", c/v, c%v);
    }
    return 0;
}