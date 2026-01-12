#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> nums;
    
    for(int i=0; i<N; i++){
        int c;
        cin >> c;
        nums.push_back(c);
    }

    int y=0, m=0;
    for(int i=0; i<nums.size(); i++){
        int time = nums[i];
        y += ((time/30)+1) * 10;
        m += ((time/60)+1) * 15;
    }

    if(y<m){
        cout << "Y " << y << endl;
    } else if(y>m){
        cout << "M " << m << endl;
    } else {
        cout << "Y M " << y << endl;
    }

    return 0;
}