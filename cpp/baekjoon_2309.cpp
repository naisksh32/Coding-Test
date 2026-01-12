#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> cm;
    int sum=0;
    for(int i=0; i<9; i++){
        int a;
        cin >> a;
        sum += a;
        cm.push_back(a);
    }

    sort(cm.begin(), cm.end());
    int skip_a, skip_b;

    for(int i=0; i<9; i++){
        for(int j=(i+1); j<9; j++){
            if(i==j){
                continue;
            }
            if(cm[i]==cm[j]){
                continue;
            }
            if((sum-cm[i]-cm[j])==100){
                skip_a = i;
                skip_b = j;
            }
        }
    }

    for(int i=0; i<9; i++){
        if(i==skip_a || i==skip_b){
            continue;
        }
        cout << cm[i] << endl;
    }

    return 0;
}