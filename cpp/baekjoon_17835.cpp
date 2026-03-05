#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 도시 수(N), 도로의 수(M), 면접장의 수(K)
int N, M, K;

// 도로 정보
struct Edge {
    int to;
    long long cost;

    bool operator<(Edge right) const {
        if (cost > right.cost)
            return true;
        if (cost < right.cost)
            return false;
        return false;
    }
};
vector<Edge> alis[100001];

// 면접장 노드
vector<int> v;

// 최소 거리를 계산할 배열
long long dist[100001];

// 한 노드로 부터 모든 노드까지의 최소 거리를 구하는 다익스트라
void dijkstra() {
    // 거리 배열 초기화
    for (int i = 1; i <= N; i++) {
        dist[i] = 1e15;
    }

    // 초기 pq 설정 및 시작점인 면접장의 정보 초기화
    priority_queue<Edge> pq;
    for (int i = 0; i < v.size(); i++) {
        pq.push({v[i], 0}); // 다음 탐색할 구간으로 면접장을 대입
        dist[v[i]] = 0;     // 면접장에서 시작함으로 면접장까지의 거리는 0
    }

    // 큐가 빌 때까지 진행
    while (!pq.empty()) {
        // 현재 시점 노드
        Edge now = pq.top();
        pq.pop();

        // 기록된 현 시점의 비용보다 더 큰 비용이 들어오면 pass
        if (dist[now.to] < now.cost)
            continue;

        // 다음 노드로 갈 수 있는 경우 탐색
        for (int i = 0; i < alis[now.to].size(); i++) {
            Edge next = alis[now.to][i];
            long long next_cost = dist[now.to] + next.cost;

            // 다음으로 가는 비용이 기록된 비용보다 더 크다면 pass
            if (dist[next.to] <= next_cost)
                continue;

            // 그게 아니면 더 절약적이므로 기록, 그리고 pq에 푸쉬
            dist[next.to] = next_cost;
            pq.push({next.to, next_cost});
        }
    }
}

int main() {
    cin >> N >> M >> K;

    for (int m = 0; m < M; m++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        // 역으로 계산하기 위해 거꾸로 대입
        alis[to].push_back({from, cost});
    }
    for (int i = 0; i < K; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    // 다익스트라를 통하여 최소 거리 계산
    dijkstra();

    // 각 최소 거리로 기록된 배열들 중 최댓값과, 그 index를 반환
    long long max_cost = 0;
    int idx = 0;
    for (int i = 1; i <= N; i++) {
        if (max_cost < dist[i]) {
            max_cost = dist[i];
            idx = i;
        }
    }

    cout << idx << '\n' << max_cost;
}
