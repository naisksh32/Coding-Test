#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;


int N, M, K;

struct Edge {
    int to;
    int cost = 1;
};
vector<Edge> alis[100001];
int dist[100001];

vector<int> nodes;
int tot_cost[10][100001];


void Dijkstra(int start, int node) {
    for (int i = 1; i <= N; i++) {
        dist[i] = 21e8;
    }

    queue<Edge> q;
    q.push({ start, 0 });
    dist[start] = 0;

    while (!q.empty()) {
        Edge now = q.front(); q.pop();

        if (dist[now.to] < now.cost) continue;

        for (int i = 0; i < alis[now.to].size(); i++) {
            Edge next = alis[now.to][i];
            int next_cost = now.cost + next.cost;

            if (dist[next.to] <= next_cost) continue;

            dist[next.to] = next_cost;
            q.push({ next.to, next_cost });
        }
    }

    for (int i = 1; i <= N; i++) {
        tot_cost[node][i] = dist[i];
    }
}

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;

        alis[from].push_back({ to, 1 });
    }

    for (int i = 0; i < K; i++) {
        int start;
        cin >> start;
        nodes.push_back(start);

        Dijkstra(start, i);
    }

    for (int i = 0; i < K; i++) {
        cout << nodes[i] << ": ";
        for (int j = 1; j <= N; j++) {
            cout << tot_cost[i][j] << ' ';
        }
        cout << '\n';
    }

    int short_node = -1;
    int min_time = 21e8;

    for (int j = 1; j <= N; j++) {

        vector<int> times;
        for (int i = 0; i < K; i++) {
            if (tot_cost[i][j] == 21e8) continue;
            times.push_back(tot_cost[i][j]);
        }

        if(!times.empty()){

            int max_time = 0;
            for (int k = 0; k < times.size(); k++) {
                max_time = max(max_time, times[k]);
            }

            min_time = min(min_time, max_time);
        }
    }

    cout << min_time;

    return 0;
}