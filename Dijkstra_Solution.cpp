class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        // Step 1: Build the graph as an adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (auto& r : roads) {
            int u = r[0], v = r[1], wt = r[2];
            graph[u].emplace_back(v, wt);
            graph[v].emplace_back(u, wt); // Since the graph is undirected
        }

        // Step 2: Initialize distance and ways vectors
        vector<long long> dist(n, LONG_MAX);  // dist[i] = shortest distance from node 0 to i
        vector<int> ways(n, 0);               // ways[i] = number of shortest paths from 0 to i

        // Min-heap to implement Dijkstra's algorithm: {distance, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        // Starting from node 0
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        // Step 3: Dijkstra's algorithm
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // Skip if we've already found a shorter path
            if (d > dist[u]) continue;

            // Explore all neighbors
            for (auto [v, wt] : graph[u]) {
                long long newDist = d + wt;

                // Case 1: Found a shorter path to neighbor
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u]; // Start new count
                    pq.push({newDist, v});
                }
                // Case 2: Found another shortest path
                else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD; // Add paths
                }
            }
        }

        // Return the number of shortest paths to node n-1
        return ways[n - 1];
    }
};
