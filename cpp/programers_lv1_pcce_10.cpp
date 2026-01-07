#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 특정 크기(mat)의 돗자리를 깔 수 있는지 확인하는 함수
bool is_mat(int mat, const vector<vector<string>>& park) {
    int rows = park.size();
    int cols = park[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            
            // 시작점이 "-1"이 아니면 돗자리 못 깐다.
            if (park[i][j] != "-1") continue;

            // [수정 1] 범위 체크: 돗자리가 공원 밖으로 나가면 즉시 포기 (continue)
            if (i + mat > rows || j + mat > cols) {
                continue;
            }

            // [수정 2] 해당 영역이 모두 "-1"인지 검사
            bool is_ok = true;
            for (int y = i; y < i + mat; y++) {
                for (int x = j; x < j + mat; x++) {
                    if (park[y][x] != "-1") {
                        is_ok = false;
                        break; // 장애물 발견 시 즉시 중단
                    }
                }
                if (!is_ok) break; // 바깥 루프도 중단
            }

            // 장애물 없이 통과했다면 true 반환
            if (is_ok) {
                return true;
            }
        }
    }
    // 모든 좌표를 다 돌아도 못 찾음
    return false;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    // [수정 3] 큰 돗자리부터 검사하기 위해 내림차순 정렬
    // 예: 5, 3, 2 순서로 정렬됨
    sort(mats.rbegin(), mats.rend());

    for (int mat : mats) {
        if (is_mat(mat, park)) {
            return mat; // 큰 것부터 찾았으므로 찾자마자 바로 리턴!
        }
    }

    // 아무것도 못 깔면 -1 반환 (문제 조건에 따라 0 또는 -1)
    // 보통 이 문제는 -1을 리턴합니다.
    return -1; 
}