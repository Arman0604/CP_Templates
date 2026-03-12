// Find the shortest distance between every pair of vertices in a graph
void floydWarshall(vector<vector<int>> &dist, int V) {

    // Try every vertex as intermediate node
    for(int k = 0; k < V; k++) {

        // pick starting vertex
        for(int i = 0; i < V; i++) {

            // pick destination vertex
            for(int j = 0; j < V; j++) {

                // check if path through k is shorter
                if(dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // print shortest distance matrix
    cout << "Shortest distance between every pair:\n";

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {

            if(dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
