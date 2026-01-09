#include <iostream>
#include <vector>
using namespace std;


int main(){
    int N;
    cin >> N;

    vector<int> check(N,0);
    for(int i=0; i<N; i++){
        int ans;
        cin >> ans;
        check[i] = ans;
    }

    vector<int> scores(N, 0);
    for(int i=0; i<N; i++){
        scores[i] = (i==0) ? (check[i] ? 1 : 0) : (check[i] ? scores[i-1]+1 : 0);
    }

    int answer=0;
    for(int i=0; i<N; i++){
        answer += scores[i];
    }
    cout << answer;

    return 0;
}