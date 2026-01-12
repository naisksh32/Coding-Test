#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b && b==c){
        cout << 10000+a*1000 << endl;
    } else if(a==b&&b!=c){
        cout << 1000+a*100;
    } else if(b==c&&c!=a){
        cout << 1000+b*100;
    } else if(c==a&&a!=b){
        cout << 1000+c*100;
    } else if(a!=b && b!=c){
        if(a>b){
            if(c>a){
                cout << c*100;
            }else{
                cout << a*100;
            }
        }else{
            if(c>b){
                cout << c*100;
            }else{
                cout << b*100;
            }
        }
    }

    return 0;
}