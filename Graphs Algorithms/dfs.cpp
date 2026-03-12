void dfs_recursive(const vector<vector<int>>& adj, vector<int>& vis, int u) {
    vis[u] = 1;
    cout << u << ' ';                 // process node (here: print)
    for (int v : adj[u]) {
        if (!vis[v]) dfs_recursive(adj, vis, v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 6; // nodes: 0,1,2,3,4,5
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // assume input is 0-indexed; if 1-indexed do: --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u); // comment out for directed graph
    }

    // Optional: sort adjacency lists for deterministic order
    for (int i = 0; i < n; ++i) sort(adj[i].begin(), adj[i].end());

    cout << "Recursive DFS order: ";
    vector<int> vis(n, 0);
    int start = 0; // starting vertex (change if you want)
    dfs_recursive(adj, vis, start);
    cout << '\n';
}
