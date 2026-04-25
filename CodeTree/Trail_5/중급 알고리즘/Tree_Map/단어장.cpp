#include <iostream>
#include <map>
using namespace std;


map<string, int> m;

int main() {
    
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        string name;
        cin >> name;

        m[name]++;
    }

    map<string, int>:: iterator it;
    for(it=m.begin(); it!=m.end(); it++){
        cout << it->first << ' ' << it->second << '\n';
    }

    return 0;
}