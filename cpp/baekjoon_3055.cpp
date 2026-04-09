#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


int N, M;
char board[51][51];
int visited[51][51];

struct Pos {
	char ch;
	int y, x;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

Pos hedgehog;
Pos biber;
vector<Pos> waters;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];

			if (board[i][j] == 'S') hedgehog = { 'S', i, j };
			else if (board[i][j] == '*') waters.push_back({ '*', i, j });
			else if (board[i][j] == 'D') biber = { 'D', i, j };
		}
	}
	memset(visited, -1, sizeof(visited));

	queue<Pos> q;
	
	for (int i = 0; i < waters.size(); i++) {
		q.push(waters[i]);
	}

	q.push(hedgehog);
	visited[hedgehog.y][hedgehog.x] = 0;

	bool flag = false;
	while (!q.empty()) {
		Pos now = q.front(); q.pop();

		for (int d = 0; d < 4; d++) {
			int ny = now.y + dy[d];
			int nx = now.x + dx[d];

			if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;
			if (board[ny][nx] == 'X') continue;	// 돌 있는 칸으로 이동 시 pass


			if (now.ch == 'S') {
				if (visited[ny][nx] != -1) continue;	// 다른 기록이 있으면 pass
				if (board[ny][nx] == '*') continue;

				visited[ny][nx] = visited[now.y][now.x] + 1;
				q.push({ 'S', ny, nx });

				if (board[ny][nx] == 'D') {
					flag = true;
					break;
				}
			}

			else if (now.ch == '*') {
				if (board[ny][nx] == 'D' || board[ny][nx] == '*') continue;

				board[ny][nx] = '*';
				q.push({ '*', ny, nx });
			}
		}

		//디버깅
		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < M; j++) {
		//		cout << visited[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}

		if (flag) break;
	}

	// 출력
	if (visited[biber.y][biber.x] != -1) {
		cout << visited[biber.y][biber.x];
	}
	else {
		cout << "KAKTUS";
	}

	return 0;
}