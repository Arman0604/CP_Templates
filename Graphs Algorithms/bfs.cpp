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

