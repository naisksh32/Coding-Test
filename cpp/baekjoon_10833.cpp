#include <iostream>
using namespace std;


int main(){
    int N;
    cin >> N;
    int rest = 0; 

    for(int n=0; n<N; n++){
        int students, apples;
        cin >> students >> apples;

        rest += apples % students;
    }

    cout << rest << endl;

    return 0;
}