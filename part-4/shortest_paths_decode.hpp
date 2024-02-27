#ifndef __shortest_paths_decode__
#define __shortest_paths_decode__

#include "graph.hpp"
#include <algorithm>
#include <vector>
#include <iostream>

inline std::vector<int> decode(const std::vector<hop_t> &DP, int v)
{
    std::vector<int> path;
    while(v != -1) {
        path.push_back(v);
        v = DP[v].vertex;
    }

    std::reverse(path.begin(), path.end());
    if(path.size() < 2){
        return {};
    }
    return path;
}

#endif // __shortest_paths_decode__
