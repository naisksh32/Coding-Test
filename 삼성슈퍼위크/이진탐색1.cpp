#include <iostream>

using namespace std;

int n, m;
int arr[100000];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        bool is_find = false;
        int sp=0, ep=n;
        while(sp<ep){
            int mid = (sp + ep) / 2;

            if(arr[mid] < x){
                sp = mid+1;
                continue;
            }
            else if(arr[mid] > x){
                ep = mid;
                continue;
            }
            else if(arr[mid] == x){
                is_find = true;
                cout << mid+1 << '\n';
                break;
            }
        }
        if(!is_find) cout << -1 << '\n'; 
    }

    // Please write your code here.

    return 0;
}
