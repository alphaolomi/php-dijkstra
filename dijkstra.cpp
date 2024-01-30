#include <iostream>
#include <vector>
#include <queue>
#include <limits>

extern "C" {
    void dijkstra(int n, int graph[][5], int source, int* dist);
}

const int INF = std::numeric_limits<int>::max();

void dijkstra_impl(int n, int graph[][5], int source, int* dist) {
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] != 0) {
                adj[i].push_back({j, graph[i][j]});
            }
        }
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    std::vector<int> dist_vec(n, INF);

    dist_vec[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &p : adj[u]) {
            int v = p.first;
            int weight = p.second;

            if (dist_vec[v] > dist_vec[u] + weight) {
                dist_vec[v] = dist_vec[u] + weight;
                pq.push({dist_vec[v], v});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        dist[i] = dist_vec[i];
    }
}

void dijkstra(int n, int graph[][5], int source, int* dist) {
    dijkstra_impl(n, graph, source, dist);
}
