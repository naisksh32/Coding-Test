#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

#define MAX_PEOPLE 100000
#define MAX_GROUP 250000


int N, G;
bool is_invite[MAX_PEOPLE + 1];

vector<int> people_in[MAX_PEOPLE + 1];
vector<int> group_in[MAX_GROUP + 1];
int group_size[MAX_GROUP + 1];


int main() {
	memset(is_invite, 0, sizeof(is_invite));
	
	cin >> N >> G;

	for (int g = 1; g <= G; g++) {
		int gs;
		cin >> gs;

		group_size[g] = gs;

		for (int i = 0; i < gs; i++) {
			int people;
			cin >> people;

			people_in[people].push_back(g);
			group_in[g].push_back(people);
		}
	}
	int ans = 0;

	// 1번 사람에게 초대장 발송
	queue<int> q;
	q.push(1);
	is_invite[1] = true;
	ans++;

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 0; i < people_in[now].size(); i++) {

			int group_num = people_in[now][i];

			group_size[group_num]--;

			if (group_size[group_num] == 1) {
				for (int j = 0; j < group_in[group_num].size(); j++) {
					if (is_invite[group_in[group_num][j]]) continue;
					
					q.push(group_in[group_num][j]);
					is_invite[group_in[group_num][j]] = true;
					ans++;
				}
			}

		}
	}

	cout << ans;
	return 0;
}