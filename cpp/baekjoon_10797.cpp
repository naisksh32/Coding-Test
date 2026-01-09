#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    cin >> n;

    vector<int> cars(5);
    for(int i=0; i<5; i++){
        int num;
        cin >> num;
        cars[i] = num;
    }

    int answer=0;
    for(int i=0; i<5; i++){
        if(n == cars[i]){
            answer++;
        }
    }
    cout << answer;

    return 0;
}