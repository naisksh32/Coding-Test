#include <iostream>
#include <queue>
using namespace std;


int main(){
    queue<int> q;
    
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        q.push(i);
    }

    int cnt = 0;
    while(q.size()!=1){
        q.pop();
        int a = q.front();
        q.push(a);
        q.pop();
    }

    cout << q.front();
    
    return 0;
}