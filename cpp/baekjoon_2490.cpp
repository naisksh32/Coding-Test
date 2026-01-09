#include <iostream>
using namespace std;


int main(){
    for(int i=0; i<3; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int sum = 4-(a+b+c+d);
        switch(sum){
            case 1:
                cout << 'A' << endl;
                break;
            case 2:
                cout << 'B' << endl;
                break;
            case 3:
                cout << 'C' << endl;
                break;
            case 4:
                cout << 'D' << endl;
                break;
            default:
                cout << 'E' << endl;
        }
    }

    return 0;
}