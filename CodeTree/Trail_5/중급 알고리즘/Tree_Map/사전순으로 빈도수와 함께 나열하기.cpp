#include <iostream>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

int N;
map<string, int> m;

int main() {
    cin >> N;
    for(int i=0; i<N; i++){
        string name;
        cin >> name;
        m[name]++;
    }

    map<string, int>::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        cout << it -> first << ' ';
        double percent = (float(it -> second) / N) * 100;
        printf("%0.4f\n", percent);
    }


    return 0;
}