#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int y, x;
struct Pos {
	int y, x;
};
int board[5][5];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };


void bfs() {
	queue<Pos> q;
	q.push({ y, x });
	board[y][x] = 1;

	while (!q.empty()) {
		Pos now = q.front(); q.pop();
		
		for (int d = 0; d < 4; d++) {
			int ny = now.y + dy[d];
			int nx = now.x + dx[d];

			if (ny >= 5 || ny < 0 || nx >= 5 || nx < 0) continue;
			if (board[ny][nx] != 0) continue;

			board[ny][nx] = board[now.y][now.x] + 1;
			q.push({ ny, nx });

		}

	}
}

int main() {
	cin >> y >> x;
	memset(board, 0, sizeof(board));

	bfs();

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}