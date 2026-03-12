// find shortest path from all nodes to the source node handling negative weights also
void bellmanFord(int V, int E, vector<Edge>& edges, int source) {

    // Step 1: create distance array
    vector<int> dist(V, INT_MAX);

    // distance from source to itself = 0
    dist[source] = 0;

    // Step 2: relax all edges V-1 times
    for(int i = 1; i <= V - 1; i++) {

        for(int j = 0; j < E; j++) {

            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].w;

            // if distance to u is known
            if(dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: check for negative weight cycle
    for(int j = 0; j < E; j++) {

        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].w;

        if(dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }

    // Step 4: print shortest distances
    cout << "Shortest distances from source:\n";

    for(int i = 0; i < V; i++) {
        cout << "Node " << i << " -> " << dist[i] << endl;
    }
}
