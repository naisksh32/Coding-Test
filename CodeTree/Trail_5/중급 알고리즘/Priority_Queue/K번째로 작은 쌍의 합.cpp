#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, k;
int arr1[100000];
int arr2[100000];

struct Node{
    int sum;
    int i, j;

    bool operator<(Node right)const{
        if(sum > right.sum) return true;
        if(sum < right.sum) return false;
        return false;
    }
};
priority_queue<Node> pq;

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    // Please write your code here.
    sort(arr1, arr1+n);
    sort(arr2, arr2+m);

    pq.push({arr1[0]+arr2[0], 0, 0});

    for(int i=0; i<k-1; i++){
        Node now = pq.top();
        pq.pop();

        if(now.j + 1 < m){
            pq.push({arr1[now.i] + arr2[now.j + 1], now.i, now.j+1});
        }

        if(now.j == 0 && now.i + 1 < n){
            pq.push({arr1[now.i + 1] + arr2[now.j], now.i+1, now.j});
        }
    }

    cout << pq.top().sum;

    return 0;
}
