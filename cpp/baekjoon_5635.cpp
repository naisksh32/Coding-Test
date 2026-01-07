#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Person {
    string name;
    int d, m, y;
};

bool compare(Person a, Person b){
    
    return make_tuple(a.y, a.m, a.d) < make_tuple(b.y, b.m, b.d);
}

int main(){
    int n;
    cin >> n;

    vector<Person> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].name >> v[i].d >> v[i].m >> v[i].y;
    }

    sort(v.begin(), v.end(), compare);

    cout << v[n-1].name << endl;
    cout << v[0].name << endl;

    return 0;
}