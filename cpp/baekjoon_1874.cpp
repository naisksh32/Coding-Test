#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;
    vector<char> result;
    int cnt = 1;
    bool possible = true;
    
    for(int i=0; i<n; i++){
        int target;
        cin >> target;

        while(cnt <= target){
            s.push(cnt);
            cnt++;
            result.push_back('+');
        }

        if(s.top() == target){
            s.pop();
            result.push_back('-');
        } else {
            cout << "NO" << endl;
            possible = false;
            break;
        }
    }

    if(possible){
        for(char op: result){
            cout << op << '\n';
        }
    }
    
    return 0;
}
