#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

long long max_HP;
long long cur_HP;
long long atk;

struct Dungeon {
	int type;
	long long atk;
	long long health;
};
vector<Dungeon> D;

bool check(long long hp) {
	long long cur_max_hp = hp;
	long long cur_cur_hp = cur_max_hp;
	long long cur_atk = atk;

	for (int i = 0; i < N; i++) {

		if (D[i].type == 1) {
			long long mon_atk = D[i].atk;
			long long mon_hp = D[i].health;

			long long hit_cnt = (mon_hp + cur_atk - 1) / cur_atk;
			long long mon_hit_cnt = hit_cnt - 1;

			cur_cur_hp -= (mon_atk * mon_hit_cnt);
			if (cur_cur_hp <= 0) return false;
		}

		else if (D[i].type == 2) {
			long long po_atk = D[i].atk;
			long long po_hp = D[i].health;

			cur_atk += po_atk;
			cur_cur_hp += po_hp;
			cur_cur_hp = min(cur_cur_hp, cur_max_hp);
		}
	}

	return true;
}


int main() {
	cin >> N >> atk;

	for (int i = 0; i < N; i++) {
		int type;
		long long attack, health;
		cin >> type >> attack >> health;

		D.push_back({ type, attack, health });
	}


	long long left = 1; long long right = 2e18;
	long long min_hp = 2e18 + 1;

	while (left <= right) {
		long long mid = (left + right) / 2;

		if (check(mid)) {
			right = mid - 1;
			min_hp = mid;
		}
		else {
			left = mid + 1;
		}
	}

	cout << min_hp;
	return 0;
}