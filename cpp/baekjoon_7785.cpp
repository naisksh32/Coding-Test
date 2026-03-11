#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int N;
struct INFO {
    string name;
    bool entrance;
};
vector<INFO> v[100001];

int hash_function(string name) {
    int idx = 0;
    int p = 1;
    for (int i = 0; i < name.length(); i++) {
        int ch = int(name[i]);
        idx += (ch * p);
        p *= 10;
    }
    return idx % 100000;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        string name, cmd;
        cin >> name >> cmd;

        int idx = hash_function(name);

        // 입장
        if (cmd == "enter") {
            // 처음 입장하는 경우
            if (v[idx].size() == 0) {
                v[idx].push_back({name, true});
            } else {
                // 해당 해쉬에서 일치하는 이름이 있는지 검색
                bool is_in = false;
                for (int p = 0; p < v[idx].size(); p++) {
                    if (v[idx][p].name == name) {
                        is_in = true;
                        // 만약 이미 존재하는 이름이라면 안에 있다고 기록
                        v[idx][p].entrance = true;
                        break;
                    }
                }
                // 없는 이름이라면 충돌이 났으므로 해당 벡터에 추가
                if (!is_in)
                    v[idx].push_back({name, true});
            }
        }
        // 퇴장
        else if (cmd == "leave") {
            for (int p = 0; p < v[idx].size(); p++) {
                if (v[idx][p].name == name) {
                    v[idx][p].entrance = false;
                }
            }
        }
    }

    vector<string> rest_p;

    for (int i = 0; i < 100001; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j].entrance) {
                rest_p.push_back(v[i][j].name);
            }
        }
    }

    sort(rest_p.begin(), rest_p.end(), greater<string>());

    for (int i = 0; i < rest_p.size(); i++) {
        cout << rest_p[i] << '\n';
    }

    return 0;
}
