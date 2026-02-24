#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
string map[5];
int visited[5][5][5][5];

struct Pos {
	int y, x;
};

int ady[5] = { -1, 1, 0, 0, 0 };
int adx[5] = { 0, 0, -1, 1, 0 };

int edy[8] = { -1, 1, 0, 0, -1, 1, 1, -1 };
int edx[8] = { 0, 0, -1, 1, 1, 1, -1, -1};

struct CH {
	Pos Elsa;
	Pos Anna;
	int time;
};


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	memset(visited, 0, sizeof(visited));

	Pos elsa, anna;
	cin >> elsa.y >> elsa.x >> anna.y >> anna.x;

	queue<CH> q;
	q.push({ elsa, anna, 0 });
	visited[elsa.y][elsa.x][anna.y][anna.x] = 1;

	while (!q.empty()) {
		CH now = q.front(); q.pop();
		Pos elsa = now.Elsa;
		Pos anna = now.Anna;
		int time = now.time;

		// 종료 조건
		if (elsa.y == anna.y && elsa.x == anna.x) {
			cout << time << " sec\n";
			break;
		}

		vector<Pos> ElsaPos;
		vector<Pos> AnnaPos;

		// 현 시점에서 감지 되었는지
		bool safety = (abs(elsa.y - anna.y) <= 2 && abs(elsa.x - anna.x) <= 2);

		// Elsa의 움직임
		for (int d = 0; d < 8; d++) {
			// 안전모드가 발생하면 대각선 이동은 불가
			if (safety && d >= 4) continue;

			int ny = elsa.y + edy[d];
			int nx = elsa.x + edx[d];

			// 경계선 확인
			if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;
			// 벽 확인
			if (map[ny][nx] == '#') continue;

			// 이동할 수 있는 곳이라면 이동
			ElsaPos.push_back({ ny, nx });
		}

		// Anna의 움직임
		for (int d = 0; d < 5; d++) {
			int ny = anna.y + ady[d];
			int nx = anna.x + adx[d];

			// 경계선 확인
			if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;
			// 벽 확인
			if (map[ny][nx] == '#') continue;

			// 이동할 수 있는 곳이라면 이동
			AnnaPos.push_back({ ny, nx });
		}

		// 엘사가 움직이는 조합이랑, 안나가 움직이는 조합을 모두 q에 푸쉬
		for (int i = 0; i < ElsaPos.size(); i++) {
			for (int j = 0; j < AnnaPos.size(); j++) {
				Pos next_E = ElsaPos[i];
				Pos next_A = AnnaPos[j];

				// 이 위치 조합이 처음 겪는 상태라면 큐에 넣음
				if (visited[next_E.y][next_E.x][next_A.y][next_A.x] == 0) {
					visited[next_E.y][next_E.x][next_A.y][next_A.x] = 1;
					q.push({ next_E, next_A, time + 1 });
				}
			}
		}

	}


	return 0;
}