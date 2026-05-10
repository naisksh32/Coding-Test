#include <iostream>
#include <set>
using namespace std;

struct Line {
	int len;
	int st;
	int end;

	bool operator<(Line right)const {
		if (len != right.len) return len < right.len;
		if (st != right.st) return st < right.st;
		return end < right.end;
	}
};

int N, M;
set<int> s_num;
set<Line> s_len;

int main() {
	cin >> N >> M;
	s_num.insert(-1);
	s_num.insert(N + 1);

	s_len.insert({ -(N + 1), -1, N + 1 });

	for (int i = 0; i < M; i++) {
		int y;
		cin >> y;

		s_num.insert(y);

		set<int>::iterator it;
		it = s_num.find(y);
		int z = *(++it);

		it = s_num.find(y);
		int x = *(--it);

		s_len.erase({ -(z - x - 1), x, z });
		s_len.insert({ -(y - x - 1), x, y });
		s_len.insert({ -(z - y - 1), y, z });

		Line best_line = *s_len.begin();
		cout << -best_line.len << '\n';
	}


	return 0;
}