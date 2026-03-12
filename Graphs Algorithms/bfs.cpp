#include <bits/stdc++.h>
using namespace std;

// BFS function
void bfs(int start, vector<vector<int>> &adj, vector<bool> &visited) {

    queue<int> q;

    // mark starting node as visited
    visited[start] = true;

    // push start node into queue
    q.push(start);

    while(!q.empty()) {

        // get front node
        int node = q.front();
        q.pop();

        // print current node
        cout << node << " ";

        // visit all neighbors of current node
        for(int neighbor : adj[node]) {

            // if neighbor is not visited
            if(!visited[neighbor]) {

                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {

    int n = 5; // number of vertices
    int m = 5; // number of edges

    // adjacency list for graph
    vector<vector<int>> adj(n);

    // edges of undirected graph
    vector<pair<int,int>> edges = {
        {0,1},
        {0,2},
        {1,3},
        {2,3},
        {3,4}
    };

    // build adjacency list
    for(auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        adj[u].push_back(v);
        adj[v].push_back(u); // because graph is undirected
    }

    vector<bool> visited(n, false);

    cout << "BFS Traversal: ";

    // start BFS from node 0
    bfs(0, adj, visited);

    return 0;
}
