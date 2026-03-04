#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int ans;

int N;               // N: 5 ~ 100
int board[110][110]; // 게임판
int max_score;

// 위치 구조체
struct Pos {
    int y, x;
};
// 핀볼 주인공 구조체
struct CH {
    Pos pos;
    int dir;
};

// 방향배열
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

// 블록 방향배열 매핑
int block[6][4] = {
    {-1, -1, -1, -1}, // 인덱스 번호를 맞추기 위한 더미 데이터
    {2, 3, 1, 0},     // ◣ (1)
    {1, 3, 0, 2},     // ◤ (2)
    {3, 2, 0, 1},     // ◥ (3)
    {2, 0, 3, 1},     // ◢ (4)
    {2, 3, 0, 1}      // ■ (5)
};

pair<Pos, Pos> wormhole[11]; // 6~10번 웜홀만 존재, index 접근

// 초기화 로직
void init() {
    memset(board, 0, sizeof(board));
    for (int i = 0; i < 11; i++) {
        wormhole[i].first = {-1, -1};
        wormhole[i].second = {-1, -1};
    }
    max_score = 0;
}
// 입력 로직
void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];

            // 웜홀 좌표를 기록
            if (board[i][j] >= 6 && board[i][j] <= 10) {
                // 첫번째에 이미 기록이 되었다면 두번째에 기록
                if (wormhole[board[i][j]].first.y != -1 &&
                    wormhole[board[i][j]].first.x != -1) {
                    wormhole[board[i][j]].second.y = i;
                    wormhole[board[i][j]].second.x = j;
                }

                else {
                    wormhole[board[i][j]].first.y = i;
                    wormhole[board[i][j]].first.x = j;
                }
            }
        }
    }

    for (int j = 0; j <= N + 1; j++) {
        board[0][j] = 5;
        board[j][0] = 5;
        board[N + 1][j] = 5;
        board[j][N + 1] = 5;
    }
}

void solve() {

    // 보드판을 살펴보면서 모든 경우를 탐색
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {

            // 0이면 빈칸임으로 시작할 수 있음
            if (board[i][j] == 0) {
                // 시작 위치
                Pos start = {i, j};

                // 출발 방향
                for (int d = 0; d < 4; d++) {

                    CH ch = {start, d}; // 주인공 정보 설정
                    int score = 0;      // 이번 회차에서 얻는 점수

                    // 이동 시작
                    while (true) {
                        // 이동
                        int dir = ch.dir;
                        int ny = ch.pos.y + dy[dir];
                        int nx = ch.pos.x + dx[dir];

                        // 이벤트

                        // 2. 이동한 칸이 블록일 때 => 이동 방향을 갱신
                        if (board[ny][nx] >= 1 && board[ny][nx] <= 5) {
                            // 새로운 방향 = 블록[블록번호][현재 이동방향]
                            dir = block[board[ny][nx]][ch.dir];
                            score++; // 점수 +1
                        }

                        // 3. 이동한 칸이 웜홀일 때
                        else if (board[ny][nx] >= 6 && board[ny][nx] <= 10) {

                            // 첫번째 웜홀의 좌표랑 동일한 경우
                            // 두번째 웜홀로 이동
                            if (ny == wormhole[board[ny][nx]].first.y &&
                                nx == wormhole[board[ny][nx]].first.x) {
                                int wny = wormhole[board[ny][nx]].second.y;
                                int wnx = wormhole[board[ny][nx]].second.x;
                                ny = wny;
                                nx = wnx;
                            }
                            // 첫번째 웜홀로 이동
                            else {
                                int wny = wormhole[board[ny][nx]].first.y;
                                int wnx = wormhole[board[ny][nx]].first.x;
                                ny = wny;
                                nx = wnx;
                            }
                        }

                        // 종료
                        // 1. 출발지로 다시 돌아오기 or 2. 블랙홀에 도착하기
                        if ((start.y == ny && start.x == nx) ||
                            board[ny][nx] == -1) {
                            break;
                        }

                        // 정상적인 이동 반영
                        ch.dir = dir;
                        ch.pos.y = ny;
                        ch.pos.x = nx;
                    }

                    // 지금까지 얻은 점수랑 최고 점수를 비교
                    max_score = max(max_score, score);
                }
            }
        }
    }

    ans = max_score;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        input();
        solve();

        cout << '#' << t << ' ' << ans << '\n';
    }
    return 0;
}