#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;

struct PoketMon {
    int ID;
    string name;
};
vector<PoketMon> v[100001];
vector<string> names;

int hashF(string name) {
    int idx = 0;
    int p = 1;
    for (int i = 0; i < name.length(); i++) {
        int ch = int(name[i]);
        idx = (idx + ch * p) % 100000;
        p = (p * 31) % 100000;
    }
    return idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    names.push_back("Dummy");

    for (int i = 1; i <= N; i++) {
        string name;
        cin >> name;

        int idx = hashF(name);
        v[idx].push_back({i, name});
        names.push_back(name);
    }

    for (int i = 0; i < M; i++) {
        string quest;
        cin >> quest;

        // 번호를 입력할 때
        if (isdigit(quest[0])) {
            int id = stoi(quest);

            cout << names[id] << '\n';
        }
        // 문자를 입력할 때
        else {
            int idx = hashF(quest);

            for (int p = 0; p < v[idx].size(); p++) {
                if (v[idx][p].name == quest) {
                    cout << v[idx][p].ID << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}
