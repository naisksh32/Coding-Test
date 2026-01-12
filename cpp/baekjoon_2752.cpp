#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> nums;
    nums.push_back(a);
    nums.push_back(b);
    nums.push_back(c);

    sort(nums.begin(), nums.end());

    cout << nums[0] << endl;
    cout << nums[1] << endl;
    cout << nums[2] << endl;

    return 0;
}