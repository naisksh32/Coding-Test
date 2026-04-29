#include <iostream>
#include <set>
using namespace std;

set<int> s;
int N, M;

int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        s.insert(n);
    }

    for(int i=0; i<M; i++){
        int n;
        cin >> n;

        if(s.lower_bound(n) == s.end()){
            cout << -1 << '\n';
        }
        else{
            cout << *s.lower_bound(n) << '\n';
        }
    }

    return 0;
}