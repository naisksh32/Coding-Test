#include <iostream>
#include <unordered_set>
using namespace std;

int ans = 0;
int N, M;

string A[1000];
string B[1000];

int idx[3];

void check() {
    unordered_set<string> AA;
    unordered_set<string> BB;
    
    for (int i = 0; i < N; i++) {
        string unique_A = "";
        string unique_B = "";
        for (int j = 0; j < 3; j++) {
            unique_A += A[i][idx[j]];
            unique_B += B[i][idx[j]];
        }
        
        AA.insert(unique_A);
        BB.insert(unique_B);
    }

    bool flag = true;
    unordered_set<string>::iterator it;
    for (it = BB.begin(); it != BB.end(); it++) {
        if (AA.find(*it) != AA.end()) {
            flag = false;
            break;
        }
    }

    if (flag) ans++;
}

void selection(int loop, int start) {
    if (loop >= 3) {
        check();
        return;
    }

    for (int i = start; i < M; i++) {
        idx[loop] = i;

        selection(loop+1, i+1);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    selection(0, 0);

    cout << ans;
    return 0;
}