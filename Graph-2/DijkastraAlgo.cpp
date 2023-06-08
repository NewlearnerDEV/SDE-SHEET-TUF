class Solution
{
    public :
        // Function to find the shortest distance of all the vertices
        // from the source vertex S.
        vector<int>
            dijkstra(int V, vector<vector<int>> adj[], int S){
                priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> dist(V, INT_MAX);
dist[S] = 0;
pq.push({0, S});
while (!pq.empty())
{
    int curDist = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    for (auto itr : adj[node])
    {

        int nd = itr[0];
        int dist2 = itr[1];
        if (dist2 + curDist < dist[nd])
        {
            dist[nd] = dist2 + curDist;
            pq.push({dist[nd], nd});
        }
    }
}
return dist;
}
}
;