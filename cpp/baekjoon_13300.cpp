#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N, K;
    cin >> N >> K;
    vector<int> students(12);
    for(int i=0; i<N; i++){
        int s, g;
        cin >> s >> g;
        if(s==0){
            students[g-1]++;
        } else if(s==1){
            students[g+5]++;
        }
    }

    int room = 0;
    for(int i=0; i<12; i++){
        room += (students[i]%K == 0) ? students[i]/K : students[i]/K + 1 ;
    }
    cout << room;
    
    return 0;
}