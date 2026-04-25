#include <iostream>
#include <map>
using namespace std;

map<int, int> m;

int main() {
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        int n;
        cin >> n;
        if(m.find(n) == m.end()){
            m[n] = i;
        }
    }

	map<int, int>::iterator it;
	for(it=m.begin(); it != m.end(); it++){
		cout << it->first << ' ' << it->second << '\n';
	}
    return 0;
}