#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;


int main(){
    vector<int> in_train(5, 0);

    for(int i=0; i<4; i++){
        int out_cnt, in_cnt;
        cin >> out_cnt >> in_cnt;

        in_train[i+1] = in_train[i] + in_cnt - out_cnt;
    }

    int max_people = 0;
    for(int i=0; i<5; i++){

        if(max_people < in_train[i]){
            max_people = in_train[i];
        }
    }

    cout << max_people << endl;

    return 0;
}