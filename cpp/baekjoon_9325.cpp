#include <iostream>
using namespace std;

int cal_cost(){
    int car_cost, options;
    cin >> car_cost >> options;
    
    for(int i=0; i<options; i++){
        int q, p;
        cin >> q >> p;
        car_cost += q*p;
    }

    return car_cost;
}

int main(){
    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        cout << cal_cost() << endl;
    }

    return 0;
}