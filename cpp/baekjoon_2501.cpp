#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> nums;

    for(int i=1; i<=N; i++){
        if(N%i == 0){
            nums.push_back(i);
        }
    }

    if(nums.size() >= K){
        cout << nums[K-1] << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}