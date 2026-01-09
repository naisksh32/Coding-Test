#include <iostream>
using namespace std;


int main(){
    int sum=0, min_num=100;

    for(int i=0; i<7; i++){
        int num;
        cin >> num;
        if(num%2==1){
            sum += num;
            if(min_num > num){
                min_num = num;
            }
        }
    }

    if(sum == 0){
        cout << -1 << endl;
    }else{
        cout << sum << "\n" << min_num << endl;
    }

    return 0;
}