#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> cards;
    
    for(int i=1; i<=20; i++){
        cards.push_back(i);
    }

    for(int t=0; t<10; t++){
        int s, e;
        cin >> s >> e;

        reverse(cards.begin() + (s - 1), cards.begin() + e);
    }

    for(int i=0; i<cards.size(); i++){
        cout << cards[i] << " ";
    }

    return 0;
}