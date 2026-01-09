#include <iostream>

using namespace std;


int main(){
    int T;
    cin >> T;
    
    for(int t=0; t<T; t++){
        int V, E;
        cin >> V >> E;
        cout << 2+E-V << endl;
    }
    return 0;
}