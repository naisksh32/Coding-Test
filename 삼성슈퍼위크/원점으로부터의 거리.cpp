#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int x[1000];
int y[1000];

struct Pos{
    int num;
    int dist;

    bool operator<(Pos right)const {
        if(dist < right.dist) return true;
        if(dist > right.dist) return false;
        if(num < right.num) return true;
        if(num > right.num) return false;
        return false;
    }
};
vector<Pos> vv;


int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    for(int i=0; i<N; i++){
        int dist = abs(x[i]) + abs(y[i]);
        vv.push_back({i+1, dist});
    }

    sort(vv.begin(), vv.end());
    for(int i=0; i<N; i++){
        cout << vv[i].num << '\n';
    }

    return 0;
}
