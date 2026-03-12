void kahnTopologicalSort(int V, vector<vector<int>> &adj) {

    // Step 1: calculate indegree of each vertex
    vector<int> indegree(V, 0);

    for(int i = 0; i < V; i++) {
        for(int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }

    // Step 2: queue to store vertices with indegree 0
    queue<int> q;

    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;

    // Step 3: process nodes
    while(!q.empty()) {

        int node = q.front();
        q.pop();

        topoOrder.push_back(node);

        // reduce indegree of neighbors
        for(int neighbor : adj[node]) {

            indegree[neighbor]--;

            if(indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Step 4: print topological order
    cout << "Topological Order: ";

    for(int node : topoOrder) {
        cout << node << " ";
    }
}
