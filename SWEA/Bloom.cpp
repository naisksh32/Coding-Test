#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int height, width;
struct Pos {
	int y, x;
};

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int board[101][101];

int main() {
	cin >> height >> width;
	memset(board, 0, sizeof(board));

	int date = 0;

	queue<Pos> q;
	for (int i = 0; i < 2; i++) {
		int y, x;
		cin >> y >> x;
		q.push({ y, x });
		board[y][x] = 1;
	}
	date = 1;

	while (!q.empty()) {
		Pos now = q.front(); q.pop();

		for (int d = 0; d < 4; d++) {
			int ny = now.y + dy[d];
			int nx = now.x + dx[d];

			if (ny >= height || ny < 0 || nx >= width || nx < 0) continue;
			if (board[ny][nx] != 0) continue;

			board[ny][nx] = board[now.y][now.x] + 1;
			date = board[ny][nx];
			q.push({ ny, nx });
		}
	}
	cout << date;
}