#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int A, B;

// 도로 정보를 저장
struct Edge {
    int to;
    long long cost;

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

long long dist[200001];    // 비용배열
vector<int> history[200001]; // 경로 추적을 위한 배열
vector<int> arr;    // 경로 기록

// 다익스트라로 최단거리 비용 & 경로 계산
void dijkstra(int start, int end) {
    // dist, history 배열 초기화
    for (int i = 1; i <= N; i++) {
        dist[i] = 1e18;
        history[i].clear();
    }
    arr.clear();

    // 초깃값 설정
    priority_queue<Edge> pq;
    pq.push({ start, 0 });
    dist[start] = 0;
    history[start].push_back(0);

    // 큐가 빌 때까지 진행
    while (!pq.empty()) {
        Edge now = pq.top(); pq.pop();

        if (dist[now.to] < now.cost) continue;

        for (int i = 0; i < alis[now.to].size(); i++) {
            Edge next = alis[now.to][i];
            long long next_cost = dist[now.to] + next.cost;

            if (dist[next.to] > next_cost) {
                dist[next.to] = next_cost;
                history[next.to].clear();
                history[next.to].push_back(now.to);
                pq.push({ next.to, next_cost });
            }
            else if (dist[next.to] == next_cost) {
                history[next.to].push_back(now.to);
            }
        }
    }

    // BFS로 최단 경로 찾기
    bool visited[200001] = { false, };
    queue<int > q;

    q.push(end);
    visited[end] = true;

    while (!q.empty()) {
        int now = q.front(); q.pop();
        if (now == 0) continue;
        arr.push_back(now);

        for (int i = 0; i < history[now].size(); i++) {
            int next = history[now][i];

            if (visited[next]) continue;

            visited[next] = true;
            q.push(next);
        }
    }

}


int main() {
    // 주어진 정보 받기
    cin >> N >> M >> A >> B;

    // 도로 정보 받기
    for (int i = 0; i < M; i++) {
        int from, to;
        long long cost;
        cin >> from >> to >> cost;

        // 양방향 연결
        alis[from].push_back({ to, cost });
        alis[to].push_back({ from, cost });
    }

    dijkstra(A, B);

    sort(arr.begin(), arr.end());

    cout << arr.size() << '\n';

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}