#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timer;
    
    void dfs(int u, int parent, vector<int> adj[],
             vector<bool> &visited,
             vector<int> &disc,
             vector<int> &low,
             vector<bool> &ap) {
        
        visited[u] = true;
        disc[u] = low[u] = timer++;
        
        int children = 0;
        
        for (int v : adj[u]) {
            
            // Ignore self-loops
            if (v == u) continue;
            
            if (!visited[v]) {
                children++;
                dfs(v, u, adj, visited, disc, low, ap);
                
                low[u] = min(low[u], low[v]);
                
                // Case 2: Non-root
                if (parent != -1 && low[v] >= disc[u])
                    ap[u] = true;
            }
            else if (v != parent) {
                low[u] = min(low[u], disc[v]);
            }
        }
        
        // Case 1: Root
        if (parent == -1 && children > 1)
            ap[u] = true;
    }
    
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        
        vector<bool> visited(V, false);
        vector<int> disc(V), low(V);
        vector<bool> ap(V, false);
        
        timer = 0;
        
        // Graph may be disconnected (safe practice)
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, visited, disc, low, ap);
            }
        }
        
        vector<int> result;
        
        for (int i = 0; i < V; i++) {
            if (ap[i])
                result.push_back(i);
        }
        
        if (result.empty())
            return {-1};
        
        sort(result.begin(), result.end());
        return result;
    }
};