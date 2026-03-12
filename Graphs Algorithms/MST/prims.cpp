// Steps -

// Start from any node (usually 0).
// Always choose the smallest weight edge that connects a visited node to an unvisited node.
// Continue until all vertices are included in the MST.

void prims(int V, vector<vector<pair<int,int>>> &adj) {

    // visited array
    vector<bool> visited(V, false);

    // min heap -> {weight, node}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    // start from node 0
    pq.push({0, 0});

    int totalWeight = 0;

    while(!pq.empty()) {

        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // if already visited, skip
        if(visited[node])
            continue;

        visited[node] = true;

        totalWeight += weight;

        cout << "Include node " << node << " with edge weight " << weight << endl;

        // check neighbors
        for(auto neighbor : adj[node]) {

            int nextNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if(!visited[nextNode]) {
                pq.push({edgeWeight, nextNode});
            }
        }
    }

    cout << "Total MST weight = " << totalWeight << endl;
}
