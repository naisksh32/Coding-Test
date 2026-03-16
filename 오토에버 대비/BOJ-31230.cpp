#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int A, B;

// 도로 정보를 저장
struct Edge {
    int to;
    int cost;

    // 정렬 방식 - cost가 작은게 우선순위
    bool operator<(Edge right) const {
        if (cost > right.cost)
            return true;
        if (cost < right.cost)
            return false;
        return false;
    }
};

// 도로 정보를 저장할 인접 리스트
vector<Edge> alis[300001];

int dist[200001];    // 비용배열
int history[200001]; // 경로 추적을 위한 배열

// 다익스트라로 최단거리 비용 & 경로 계산
void dijkstra(int start, int end) {
    // dist, history 배열 초기화
}

int main() {
    // 주어진 정보 받기
    cin >> N >> M >> A >> B;

    // 도로 정보 받기
    for (int i = 0; i < N; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        // 양방향 연결
        alis[from].push_back({to, cost});
        alis[to].push_back({from, cost});
    }

    dijkstra(A, B);

    return 0;
}