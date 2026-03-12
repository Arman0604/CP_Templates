// structure to represent an edge
struct Edge {
    int u, v, weight;
};

// comparator for sorting edges by weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// find function for DSU
int findParent(int node, vector<int> &parent) {

    if(parent[node] == node)
        return node;

    return parent[node] = findParent(parent[node], parent);
}

// union function for DSU
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {

    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if(rootU == rootV)
        return;

    if(rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    }
    else if(rank[rootV] < rank[rootU]) {
        parent[rootV] = rootU;
    }
    else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

void kruskal(int V, vector<Edge> &edges) {

    // sort edges by weight
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(V);
    vector<int> rank(V, 0);

    // initially every node is its own parent
    for(int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int mstWeight = 0;

    cout << "Edges in MST:\n";

    for(auto edge : edges) {

        int u = edge.u;
        int v = edge.v;
        int w = edge.weight;

        // check if adding edge creates cycle
        if(findParent(u, parent) != findParent(v, parent)) {

            cout << u << " - " << v << " : " << w << endl;

            mstWeight += w;

            unionSet(u, v, parent, rank);
        }
    }

    cout << "Total MST Weight = " << mstWeight << endl;
}
