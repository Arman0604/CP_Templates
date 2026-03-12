struct DSU {
    int n;
    vector<int> parent;
    vector<int> sz; // size of each component (valid only at root)

    DSU(int n=0) { init(n); }

    void init(int N) {
        n = N;
        parent.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    // find with path compression
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    // unite by size: attach smaller tree under larger tree
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    // check if a and b are in same set
    bool same(int a, int b) {
        return find(a) == find(b);
    }

    // size of component containing x
    int component_size(int x) {
        return sz[find(x)];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 6; // nodes: 0,1,2,3,4,5
    DSU dsu(n);

    // make some unions
    dsu.unite(0, 1);
    dsu.unite(2, 3);
    dsu.unite(1, 2); // now 0,1,2,3 are connected
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
  
}
