// shortest path from all nodes from source
void dijkstra(int n, vector<vector<pair<int,int>>> &adj, int src) {

    // distance array
    vector<int> dist(n, INT_MAX);

    // min priority queue -> {distance, node}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    // distance to source is 0
    dist[src] = 0;

    // push source node
    pq.push({0, src});

    while(!pq.empty()) {

        int currentDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // visit all neighbors
        for(auto edge : adj[node]) {

            int neighbor = edge.first;
            int weight = edge.second;

            // relaxation step
            if(dist[node] + weight < dist[neighbor]) {

                dist[neighbor] = dist[node] + weight;

                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    // print shortest distances
    cout << "Shortest distances from source:\n";

    for(int i = 0; i < n; i++) {
        cout << "Node " << i << " -> " << dist[i] << endl;
    }
}
