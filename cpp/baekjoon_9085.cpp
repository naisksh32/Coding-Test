#include <iostream>
#include <vector>
using namespace std;


int main(){
    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        int p, sum=0;
        cin >> p;
        vector<int> arr(p);
        
        for(int i=0; i<p; i++){
            int num;
            cin >> num;
            arr[i] = num;
        }
        for(int j=0; j<arr.size(); j++){
            sum += arr[j];
        }
        cout << sum << endl;
    }

    return 0;
}