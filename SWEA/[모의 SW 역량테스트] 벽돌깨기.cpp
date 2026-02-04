#include <iostream>
#include <vector>
using namespace std;
 
int N, W, H;
vector<vector<int>> board;
vector<vector<vector<int>>> copy_boards(4);
 
int max_sum = 0;    // 최종 정답이 될 합계 변수
int sum = 0;        // 각 리프노드마다 깨트린 벽돌을 합산할 변수
int partial_sum;    // 단계적으로 부순 합
vector<int> partial_sums;
 
struct Pos {
    int y;
    int x;
};
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
 
 
 
// 재귀적으로 벽돌을 부수는 함수
void break_brick(int power, Pos pos) {
    // 1. 기저 조건: power가 0이면 부술 블록이 없음
    if (power == 0) return;
 
    // 2. 재귀 조건:
    // 일단 본인 위치는 0으로 변경
    board[pos.y][pos.x] = 0;
    // 벽돌 1개를 부숨
    partial_sum++;
 
    // 변경 후 전이 범위가 없는 1은 바로 종료
    if (power == 1) return;
 
    // 4방향
    for (int dir = 0; dir < 4; dir++) {
        //파워만큼 앞으로
        for (int p = 1; p < power; p++) {
            int ny = pos.y + dy[dir] * p;
            int nx = pos.x + dx[dir] * p;
 
            // 만약 보드판 범위를 벗어나면 다음 case로
            if (ny >= H || ny < 0 || nx >= W || nx < 0) continue;
 
            // 이동한 범위에서 연쇄반응 탐지
            break_brick(board[ny][nx], { ny, nx });
 
        }
    }
 
}
 
void cleaning_board() {
    // 열별로 밑에 0값이 있으면 아래로 정리
    for (int w = 0; w < W; w++) {
        for (int h = H - 1; h >= 0; h--) {
            // 정렬이 안된 수를 발견하면
            if (board[h][w] != 0) {
                for (int hh = H - 1; hh >= h; hh--) {
                    // 제일 아래 0인 수를 발견
                    if (board[hh][w] == 0) {
                        // 두 수의 위치를 교환
                        int tmp = board[h][w];
                        board[h][w] = board[hh][w];
                        board[hh][w] = tmp;
                    }
                }
 
            }
        }
    }
 
}
 
vector<int> path;
 
// 메인이 될 구슬을 집어 넣는 재귀함수
void func(int level) {
 
    // 1. 기저 조건: 구슬을 넣는 갯수(N)를 초과했을 때
    if (level >= N) {
        // for (int i = 0; i < path.size(); i++) {
        //     cout << path[i] << " ";
        // }
        // cout << "해당 루트의 합계: " << sum << ": [";
        // int s = 0;
        // for(int i=0; i<N; i++){
        //     cout << partial_sums[i] << " ";
        //     s+= partial_sums[i];
        // }
        // cout << "] " << s;
        // cout << endl;
 
        // 최종 벽돌 갯수랑 지금까지 더한 벽돌 갯수 비교
        if (max_sum < sum) {
            max_sum = sum;
        }
        return;
    }
 
    // 보드를 변경 전 백업
    copy_boards[level] = board;
 
    // 2. 재귀 조건: 구슬을 집어넣을 수 있는 경우(가로 길이 W)
    for (int w = 0; w < W; w++) {
        // 가지치기 로직 - 넣고자 하는 열이 모두 0인 경우 (최악도 20,000이라 굳이?)
        bool is_branch = true;
        for (int h = 0; h < H; h++) {
           if (board[h][w] != 0) is_branch = false;
        }
        if (is_branch) continue;
 
 
        // 3. 들어가면서 처리
        partial_sum = 0;
        for (int h = 0; h < H; h++) {
            if (board[h][w] != 0) {
                // 벽돌을 부수는 함수 트리거
                break_brick(board[h][w], { h, w });
                partial_sums.push_back(partial_sum);
                // 공은 한번만 충돌함.
                break;
            }
        }
        // 충돌 후 공들을 정렬
        cleaning_board();
        // 부분합을 전체 합에 합산
        sum += partial_sums[level];
        path.push_back(w);
 
        // 4. 재귀
        func(level + 1);    // 그 다음 구슬을 투입
 
        bool flag = true;
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(board[i][j] != 0) flag = false;
            }
        }
        if(flag){
            max_sum = sum;
            return;
        }
         
 
        // 5. 나오면서 처리 - 다시 보드 원상복귀
        // 보드 원상복귀
        board = copy_boards[level];
        // 부분합을 전체 합에서 차감
        sum -= partial_sums[level];
        partial_sums.pop_back();
        path.pop_back();
 
    }
}
 
 
 
 
int main() {
    int T;
    cin >> T;
     
    for(int t=1; t<=T; t++){
        cin >> N >> W >> H;
        board.assign(H, vector<int>(W));
        copy_boards.resize(N);
        int cnt =0;
        max_sum = 0;
        sum = 0;
        partial_sums.clear();
        path.clear();
         
        // 보드 설정
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> board[i][j];
            }
        }
 
         
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(board[i][j] != 0) cnt++;
            }
        }
        // cout << "총 블럭 갯수: " << cnt << endl;
         
        func(0);
     
        cout <<'#' << t << ' '<< (cnt - max_sum) << endl;
    }
     
    return 0;
}