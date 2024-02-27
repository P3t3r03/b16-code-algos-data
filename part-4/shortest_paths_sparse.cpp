#include "shortest_paths_sparse.hpp"
#include <priority_queue.hpp>

#include <cmath>
#include <iostream>

std::vector<hop_t> bellman_ford(const SparseGraph &graph, const int source,
                                bool &has_negative_cycle)
{
    const int V = static_cast<int>(graph.size());
    auto DP = std::vector<hop_t>(V, {inf, -1});
    DP[source].weight = 0.0;
    has_negative_cycle = false;

    for(int i = 0; i < V-1 ; i++) {
        has_negative_cycle = false;
        for(int u = 0; u < V; u++) {
            for(const auto& edge : graph[u]) {
                int v = edge.vertex;
                float weight = edge.weight;
                if (DP[u].weight < inf && DP[u].weight + weight < DP[v].weight) {
                    DP[v].weight = DP[u].weight + weight;
                    DP[v].vertex = u;
                }
            }
        }
    }
    return DP;
}

struct triplet_t {
    float d;
    int r;
    int v;
};

std::vector<hop_t> dijkstra(const SparseGraph &graph, const int source)
{
    assert(source >= 0);
    assert(source < (signed)graph.size());

    const int V = static_cast<int>(graph.size());
    auto DP = std::vector<hop_t>(graph.size(), {inf, -1});
    DP[source].weight = 0.0;

    std::vector<bool> Open(V, true);

    while(true) {
        float D_star = inf;
        int v_star = -1;
        for(int v = 0; v < V; v++) {
            if(Open[v] && DP[v].weight < D_star) {
                D_star = DP[v].weight;
                v_star = v;
            }
        }
        if(v_star == -1) {
            break;
        }

        Open[v_star] = false;

        for(const auto& near : graph[v_star]) {
            int v = near.vertex;
            float weight = near.weight;
            if(Open[v] && DP[v_star].weight + weight < DP[v].weight) {
                DP[v].weight = DP[v_star].weight + weight;
                DP[v].vertex = v_star;
            }
        }
    }

    return DP;
}
