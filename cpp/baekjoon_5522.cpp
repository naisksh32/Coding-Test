#include <iostream>
using namespace std;


int main(){
    int sum=0;
    for(int i=0; i<5; i++){
        int score;
        cin >> score;
        sum += score;
    }
    cout << sum << endl;
    return 0;
}