#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    vector<int> a_arr;
    vector<int> b_arr;
    vector<int> ab_arr;

    for(int i=1; i<=a; i++){
        if(a%i==0){
            a_arr.push_back(i);
        }
    }
    for(int j=1; j<=b; j++){
        if(b%j==0){
            b_arr.push_back(j);
        }
    }
    
    // 최대 공약수
    for(int i=0; i<a_arr.size(); i++){
        for(int j=0; j<b_arr.size(); j++){
            if(a_arr[i]==b_arr[j]){
                ab_arr.push_back(a_arr[i]);
            }
        }
    }
    int min_num = ab_arr[ab_arr.size()-1];
    cout << min_num << endl;
    
    // 최소 공배수
    int max_num;
    max_num = (a*b)/min_num;
    cout << max_num << endl;
    
    return 0;
}