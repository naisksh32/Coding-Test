#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> nums;
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        nums.push_back(n);
    }

    int v, cnt=0;
    cin >> v;
    for(int i=0; i<N; i++){
        if(v == nums[i]) cnt++;
    }

    cout << cnt;
    
    return 0;
}