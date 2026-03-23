#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, Q;
int board[20][20];          // 미생물들이 배치될 보드
int move_board[20][20];     // 미생물들이 이동할 보드
int visited[20][20];        // 방문 배열
int meeting[51][51];        // 군집별 만남 저장할 배열

// 위치 정보 구조체 
struct Pos {
    int y, x;

    bool operator<(const Pos& right) const {
        if (x < right.x) return true;
        if (x > right.x) return false;
        if (y < right.y) return true;
        if (y > right.y) return false;
        return false;
    }
};

// 4 방향 배열
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

// 미생물 군집의 정보
struct Info {
    vector<Pos> pp;         // 군집의 미생물 위치 정보
    int width, height;      // 군집의 미생물 가로 세로 길이
    int many;               // 군집의 미생물 갯수 (pp.size)
    int min_y, min_x;       // ✨ [수정] 군집의 진짜 Top-Left 좌표!
};

vector<Info> colony[51];

// 미생물 군집 정보를 종합하는 구조체
struct Colony_Infoes {
    int colony_num;
    vector<Pos> pp;
    int width, height;
    int many;
    int min_y, min_x;       // ✨ [수정] 군집의 진짜 Top-Left 좌표!

    // 주어진 조건에 맞는 정렬 (크기 내림차순 -> 번호 오름차순)
    bool operator<(const Colony_Infoes& right) const {
        if (many > right.many) return true;
        if (many < right.many) return false;
        if (colony_num < right.colony_num) return true;
        if (colony_num > right.colony_num) return false;
        return false;
    }
};

// 디버깅용 보드 출력
void show() {
    cout << "=================" << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

// BFS 탐색으로 미생물 그룹 확인
void check_group(int g, Pos n) {
    queue<Pos> q;
    q.push(n);
    visited[n.y][n.x] = 1;

    int min_x = n.x, min_y = n.y;
    int max_x = n.x, max_y = n.y;
    vector<Pos> ppp;

    while (!q.empty()) {
        Pos now = q.front(); q.pop();
        ppp.push_back(now);

        min_x = min(min_x, now.x);
        min_y = min(min_y, now.y);
        max_x = max(max_x, now.x);
        max_y = max(max_y, now.y);

        for (int d = 0; d < 4; d++) {
            int ny = now.y + dy[d];
            int nx = now.x + dx[d];

            if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;
            if (board[ny][nx] != g) continue;
            if (visited[ny][nx] != 0) continue;

            visited[ny][nx] = 1;
            q.push({ ny, nx });
        }
    }

    // ✨ [수정] 너비와 높이는 최댓값-최솟값에 반드시 +1을 해야 실제 칸 수가 됩니다.
    int width = max_x - min_x + 1;
    int height = max_y - min_y + 1;
    int many = ppp.size();

    sort(ppp.begin(), ppp.end());

    // ✨ [수정] min_y, min_x 도 함께 저장해줍니다.
    colony[g].push_back({ ppp, width, height, many, min_y, min_x });
}

// 미생물을 투입하는 함수
void input_virus(int node) {
    for (int i = 0; i < 51; i++) {
        colony[i].clear();
    }

    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;

    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {
            board[i][j] = node;
        }
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) continue;
            if (visited[i][j] != 0) continue;
            check_group(board[i][j], { i, j });
        }
    }

    // 군집이 나누어졌는지 판단하여 증발 처리
    for (int i = 1; i <= node; i++) {
        if (colony[i].size() > 1) {
            for (int j = 0; j < colony[i].size(); j++) {
                for (int k = 0; k < colony[i][j].pp.size(); k++) {
                    Pos now = colony[i][j].pp[k];
                    board[now.y][now.x] = 0;
                }
            }
            colony[i].clear();
        }
    }
}

// 미생물의 이동을 구현
void move_virus() {
    memset(move_board, 0, sizeof(move_board));

    vector<Colony_Infoes> cc;
    for (int i = 1; i <= Q; i++) {
        if (colony[i].size() == 0) continue;
        Info info = colony[i][0];
        cc.push_back({ i, info.pp, info.width, info.height, info.many, info.min_y, info.min_x });
    }
    sort(cc.begin(), cc.end());

    for (int k = 0; k < cc.size(); k++) {
        Colony_Infoes ff = cc[k];

        bool is_set = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {

                if (j + ff.width > N) continue;
                if (i + ff.height > N) continue;

                // 실제 미생물 블록들만 정밀 검사
                bool is_in = true;
                for (int p = 0; p < ff.pp.size(); p++) {
                    Pos pos = ff.pp[p];
                    int ny = i + (pos.y - ff.min_y);
                    int nx = j + (pos.x - ff.min_x);

                    if (move_board[ny][nx] != 0) {
                        is_in = false;
                        break;
                    }
                }
                if (!is_in) continue;

                // 검사 통과 시 배치
                for (int p = 0; p < ff.pp.size(); p++) {
                    Pos pos = ff.pp[p];
                    int ny = i + (pos.y - ff.min_y);
                    int nx = j + (pos.x - ff.min_x);
                    move_board[ny][nx] = ff.colony_num;
                }

                is_set = true;
                break;
            }
            if (is_set) break;
        }
    }
    memcpy(board, move_board, sizeof(board));
}

// 인접한 군집들의 값의 곱을 누적합
int check_result() {
    int result = 0;
    memset(meeting, 0, sizeof(meeting));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int now = board[i][j];

            // ✨ [방어막] 현재 칸이 0이면 무시
            if (now == 0) continue;

            for (int d = 0; d < 4; d++) {
                int ny = i + dy[d];
                int nx = j + dx[d];

                if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;

                int next_cell = board[ny][nx];

                // ✨ [방어막] 옆 칸이 0이면 무시 (Out of Bounds 원천 차단)
                if (next_cell == 0) continue;

                if (now != next_cell) {
                    // ✨ [수정] 양쪽 다 0인지 확인하는 완벽한 조건문!
                    if (meeting[now][next_cell] == 0 && meeting[next_cell][now] == 0) {
                        int ga = colony[now][0].many;
                        int gb = colony[next_cell][0].many;
                        result += ga * gb;

                        meeting[now][next_cell] = 1;
                        meeting[next_cell][now] = 1;
                    }
                }
            }
        }
    }

    return result;
}

int main() {
    // 입출력 속도 향상 (선택 사항이지만 코딩 테스트에서 유용합니다)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;

    for (int i = 1; i <= Q; i++) {
        input_virus(i);
        move_virus();
        int ans = check_result();
        cout << ans << '\n';
    }

    return 0;
}
