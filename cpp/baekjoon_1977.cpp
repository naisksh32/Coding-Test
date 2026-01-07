#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void check_perfect_num(int M, int N){
    int sum_perfect_num=0;
    vector<int> perfect_nums;

    int i = 1;
    while(i*i <= N){
        if (i*i >=M && i*i <= N){
            perfect_nums.push_back(i*i);
        }
        i++;
    }

    if(perfect_nums.empty()){
        cout << -1 << endl;
        return;
    }

    for(int k=0; k<perfect_nums.size(); k++){
        sum_perfect_num += perfect_nums[k];
    }

    cout << sum_perfect_num << endl;
    cout << perfect_nums[0] << endl;
}


int main(){
    int M, N;
    cin >> M >> N;

    check_perfect_num(M, N);
    
    return 0;
}