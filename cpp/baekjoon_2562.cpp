#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums;
    for(int i=0; i<9; i++){
        int n;
        cin >> n;

        nums.push_back(n);
    }

    int max_num = 0, seq=0;
    for(int i=0; i<9; i++){
        if(max_num<nums[i]){
            max_num = nums[i];
            seq = i+1;
        }
    }

    cout << max_num << endl;
    cout << seq << endl;

    return 0;
}