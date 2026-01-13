#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> nums(10);

    for(int i=0; i<10; i++){
        for(auto c: s){
            if(c == (i+'0')) nums[i]++;
        }
    }

    int temp = (nums[6] + nums[9])%2==0 ? (nums[6] + nums[9])/2 : (nums[6] + nums[9])/2+1;
    nums[6] = temp;
    nums[9] = temp;

    int max_num=0;
    for(int i =0; i<10; i++){
        if(max_num<nums[i]) max_num = nums[i];
    }

    cout << max_num;

    return 0;
}