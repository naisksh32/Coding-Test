#include <iostream>
#include <vector>
using namespace std;


// 4x4 그리드
vector<vector<int>> grid(4, vector<int>(4));

// 좌표 정보를 저장할 구조체
struct Pos {
	int y;
	int x;
};
// [우, 우하, 하, 좌하, 좌, 상좌, 상, 상우] 방향배열
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

// 블록의 모양을 저장할 벡터 자료구조
vector<vector<vector <int>>> block_shape;


// 임시 변수
int cnt = 0;	// 그리드 내 생성된 블럭의 갯수 

// 1단계 구현
// 4x4에서 모든 블록의 배치 => 재귀 (DFS)
void set_Block(int level, Pos pos) {
	// 1. 기저: 블록을 4개 배치하면 종료
	if (level >= 4) {
		
		bool is_duplicated = false;
		for (int i = 0; i < block_shape.size(); i++) {
			if (block_shape[i] == grid) {
				is_duplicated = true;
				break;
			}
		}
		// 해당 모양을 저장
		if(!is_duplicated) block_shape.push_back(grid);

		return;
	}

	// 2. 재귀
	for (int dir = 0; dir < 8; dir++) {
		// 이동할 다음 좌표
		int ny = pos.y + dy[dir];
		int nx = pos.x + dx[dir];
		
		// 3. 가지치기
		// 주어진 4x4 그리드 밖으로 나가는 경우
		if (ny >= 4 || ny < 0 || nx >= 4 || nx < 0) continue;
		// 이미 간 전적이 있는 경우;
		if (grid[ny][nx] == 1) continue;
		// 다음으로 지정한 칸 옆에 인접 칸이 없을 경우
		bool is_near = false;
		for (int i = 0; i < 8; i = i + 2) {
			int cny = ny + dy[i];
			int cnx = nx + dx[i];
			if (cny >= 4 || cny < 0 || cnx >= 4 || cnx < 0) continue;

			if (grid[cny][cnx] == 1) is_near = true;
		}
		if (!is_near) continue;

		// 4. 들어가기
		grid[ny][nx] = 1;

		// 재귀 함수
		set_Block(level + 1, { ny, nx });

		// 5. 나오기
		grid[ny][nx] = 0;
	}
}

void First_Step() {
	//cout << "그리드 초기화" << endl;
	// 그리드 초기화
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			grid[i][j] = 0;
		}
	}

	//cout << "블럭 생성" << endl;
	// 그리드 좌표 별 블록 생성
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			grid[i][j] = 1;
			set_Block(1, { i, j });
			grid[i][j] = 0;

		}
	}

	//// 블럭 확인 출력
	//for (int k = 0; k < block_shape.size(); k++) {
	//	cout << "------------------------" << endl;
	//	for (int i = 0; i < 4; i++) {
	//		for (int j = 0; j < 4; j++) {
	//			cout << block_shape[k][i][j] << " ";
	//		}
	//		cout << endl;
	//	}
	//	cnt++;
	//}

	//cout << "총 블럭 생성 갯수: " << cnt;
}

// 2단계 구현
// NxM에서 4x4 그리드를 적용하여 최댓값 탐색
// 보드의 세로(N), 가로(ㅡ)
int N, M;
// 보드판 (최댓값 500)
int board[500][500];
// 합계와 최댓값
int sum = 0, max_sum = 0;

void Second_Step() {
	// 보드 가로 세로 입력받기
	cin >> N >> M;
	// 보드 입력 받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	// board 안 격자를 설치하여 판별
	for (int i = 0; i < N - 3; i++) {
		for (int j = 0; j < M - 3; j++) {

			for (int k = 0; k < block_shape.size(); k++) {

				sum = 0;
				for (int y = 0; y < 4; y++) {
					for (int x = 0; x < 4; x++) {

						if (block_shape[k][y][x] == 1) {
							sum += board[i + y][j + x];
						}

					}
				}

				max_sum = max(max_sum, sum);
			}
		}
	}
}

int main() {
	First_Step();
	Second_Step();

	cout << max_sum;
	return 0;
}